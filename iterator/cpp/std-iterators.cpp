#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<std::string> names {"andrei", "bogdan", "cristi", "danut"};

    std::vector<std::string>::iterator it = std::begin(names);
    //    std::vector<std::string>::iterator it = names.begin();

    std::cout << "first name is: " << *it << '\n';
    ++it;
    std::cout << "second name is: " << *it << '\n';
    it->append(std::string{" pop"});
    std::cout << "second name is: " << *it << '\n';

    while (++it != names.end())
    {
        std::cout << std::addressof(it) << " " << *it << '\n';
    }

    for (auto ri = std::rbegin(names); ri != std::rend(names); ++ri)
    {
        std::cout << *ri;
        if (ri + 1 != std::rend(names)) { std::cout << ", "; }
    }
    std::cout << '\n';

//    std::vector<std::string>::const_reverse_iterator rIt = std::crbegin(names);
    //*rIt += std::string(" test"); // does not work since it is const

    for (auto&& name : names)
    {
        std::cout << "name = " << name << '\n';
    }

    return 0;
}
