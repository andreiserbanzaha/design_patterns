#include <iostream>
#include <string>

template <typename T>
struct BinaryTree;

template <typename T>
struct Node
{
    Node(T aValue)
        : value{aValue}
    {
    }

    Node(T aValue, Node<T>* aLeft, Node<T>* aRight)
        : value{aValue}
        , left{aLeft}
        , right{aRight}
    {
        this->left->tree = this->right->tree = tree;
        this->left->parent = this->right->parent = this;
    }

    void setTree(BinaryTree<T>* aTree)
    {
        tree = aTree;
        if (left) left->setTree(aTree);
        if (right) right->setTree(aTree);
    }

    ~Node()
    {
        if (left) delete left;
        if (right) delete right;
    }

    T value = T{};
    Node<T>* parent{nullptr};
    Node<T>* left{nullptr};
    Node<T>* right{nullptr};
    BinaryTree<T>* tree{nullptr};
};

template <typename T>
struct BinaryTree
{
    BinaryTree(Node<T>* aRoot)
        : root{aRoot}
    {
        root->setTree(this);
    }

    ~BinaryTree()
    {
        if (root) delete root;
    }

    template<typename U>
    struct PreOrderIterator
    {
        Node<U>* current;
        PreOrderIterator(Node<U>* aCurrent)
            : current{aCurrent}
        {
        }

        bool operator!=(PreOrderIterator<U> const& other)
        {
            return current != other.current;
        }

        PreOrderIterator<U>& operator++()
        {
            if (current->right)
            {
                current = current->right;
                while (current->left)
                {
                    current = current->left;
                }
            }
            else
            {
                Node<T>* p = current->parent;
                while (p && current == p->right)
                {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }

        Node<U>& operator*()
        {
            return *current;
        }
    };

    PreOrderIterator<T> begin()
    {
        Node<T>* n = root;
        if (n)
        {
            while (n->left)
            {
                n = n->left;
            }
        }
        return PreOrderIterator<T>{n};
    }

    PreOrderIterator<T> end()
    {
        return PreOrderIterator<T>{nullptr};
    }

    Node<T>* root{nullptr};
};

int main()
{
    BinaryTree<std::string> family
    {
        new Node<std::string>
        {
            "me",
            new Node<std::string>
            {
                "mother",
                new Node<std::string>{"mother's mother"},
                new Node<std::string>{"mother's father"},
            },
            new Node<std::string>
            {
                "father"
            }
        }
    };

    for (auto it = family.begin(); it != family.end(); ++it)
    {
        std::cout << (*it).value << '\n';
    }

    return 0;
}
