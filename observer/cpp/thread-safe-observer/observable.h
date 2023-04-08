#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <mutex>

template <typename>
class Observer;

template <typename T>
class Observable
{
public:
    void notify(T& source, std::string const& fieldName)
    {
        std::scoped_lock<std::mutex> lock{_mtx};
        for (auto observer : _observers)
        {
            // if (observer) // option 1 avoid deadlock
            observer->fieldChanged(source, fieldName);
        }
    }

    void subscribe(Observer<T>& observer)
    {
        std::scoped_lock<std::mutex> lock{_mtx};
        _observers.push_back(&observer);
    }

    void unsubscribe(Observer<T>& observer)
    {
        // option 1 avoid deadlock -> only set to nullptr (not remove)
        //        auto it = std::find(std::begin(_observers),
        //                            std::end(_observers),
        //                            &observer);
        //        if (it != std::end(_observers)) { *it = nullptr; }

        std::scoped_lock<std::mutex> lock{_mtx};
        _observers.erase(std::remove(_observers.begin(),
                                     _observers.end(),
                                     &observer),
                         _observers.end());
    }

private:
    std::vector<Observer<T>*> _observers;
    std::mutex _mtx;
    //std::recursive_mutex _mtx; // option 2 to avoid deadlock
};
