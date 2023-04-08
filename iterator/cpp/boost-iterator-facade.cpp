#include <iostream>
#include <string>
#include <boost/iterator/iterator_facade.hpp>
#include <algorithm>

struct Node
{
    std::string value;
    Node* next{nullptr};

    Node(std::string const& aValue)
        : value{aValue}
    {
    }

    Node(std::string const& aValue, Node* aParent)
        : value{aValue}
    {
        aParent->next = this;
    }
};

struct ListIterator :
        public boost::iterator_facade<ListIterator, Node, boost::forward_traversal_tag>
{
    Node* current{nullptr};

    ListIterator() {}

    ListIterator(Node* aCurrent)
        : current{aCurrent}
    {}

private:
    friend class boost::iterator_core_access;

    void increment() { current = current->next; }

    bool equal(ListIterator const& other) const
    {
        return other.current == current;
    }

    Node& dereference() const
    {
        return *current;
    }
};

int main()
{
    Node alpha{"alpha"};
    Node beta{"beta", &alpha};
    Node gamma{"gamma", &beta};

    std::for_each(ListIterator{&alpha}, ListIterator{}, [](Node const& n){
        std::cout << n.value << '\n';
    });

    return 0;
}
