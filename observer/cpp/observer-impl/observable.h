#pragma once

#include <string>
#include <vector>
#include <algorithm>

template <typename>
class Observer;

template <typename T>
class Observable
{
public:
    void notify(T& source, std::string const& fieldName)
    {
        for (auto observer : _observers)
        {
            observer->fieldChanged(source, fieldName);
        }
    }

    void subscribe(Observer<T>& observer)
    {
        _observers.push_back(&observer);
    }

    void unsubscribe(Observer<T>& observer)
    {
        _observers.erase(std::remove(_observers.begin(),
                                     _observers.end(),
                                     &observer),
                         _observers.end());
    }

private:
    std::vector<Observer<T>*> _observers;
};
