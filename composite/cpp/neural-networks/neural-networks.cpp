#include <iostream>
#include <vector>
#include <ostream>
#include <type_traits>
#include <utility>

// Curiously recurring template pattern (CRTP)
template <typename Self>
class SomeNeurons
{
public:
    template<typename T>
    void connectTo(T& other)
    {
        for(typename Self::NeuronRefType from : *static_cast<Self*>(this))
        {
            for(typename Self::NeuronRefType to : other)
            {
                from.out.push_back(&to);
                to.in.push_back(&from);
            }
        }
    }
};

class Neuron : public SomeNeurons<Neuron>
{
public:
    using NeuronRefType = Neuron&;
    using NeuronPtrType = Neuron*;

    Neuron()
    {
        static int id{1};
        this->_id = id++;
    }

    Neuron* begin()
    {
        return this;
    }

    Neuron* end()
    {
        return this + 1;
    }

    friend std::ostream& operator<<(std::ostream& os, Neuron const& obj)
    {
        for (Neuron* n : obj.in)
        {
            os << n->getId() << "\t-->\t[" << obj.getId() << "]\n";
        }

        for (Neuron* n : obj.out)
        {
            os << "[" << obj.getId() << "]\t-->\t" << n->getId() << '\n';
        }

        return os;
    }

    unsigned int getId() const
    {
        return _id;
    }

public:
    std::vector<Neuron*> in;
    std::vector<Neuron*> out;

private:
    unsigned int _id;
};

// very bad idea! - no virtual destructor for std::vector
class NeuronLayer : public std::vector<Neuron>, public SomeNeurons<NeuronLayer>
{
public:
    using NeuronRefType = Neuron&;
    using NeuronPtrType = Neuron*;

    NeuronLayer(int count)
    {
        while (count-- > 0)
        {
            emplace_back(Neuron{});
        }
    }

    friend std::ostream& operator<<(std::ostream& os, NeuronLayer const& obj)
    {
        for (auto& n : obj)
        {
            os << n;
        }
        return os;
    }
};

int main()
{
    // scenario 1: connect neuron to neuron
    Neuron n1, n2;
    n1.connectTo(n2);
    std::cout << n1 << n2 << '\n';

    // scenario 2: connect neuron to layer or layer to neuron
    NeuronLayer layer1{2}, layer2{3};
    n1.connectTo(layer1);
    layer2.connectTo(n2);

    // scenario 3: connect layer to layer
    layer1.connectTo(layer2);

    std::cout << layer1 << '\n';

    return 0;
}
