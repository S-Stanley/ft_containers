#include <iostream>
#include <vector>

#include "vector.hpp"

int     main(void)
{
    ft::vector<int>     mine;
    std::vector<int>    their;

    std::cout << "** size **" << std::endl;
    std::cout << mine.size() << std::endl;
    std::cout << their.size() << std::endl;

    std::cout <<  std::endl << "** push back: 4 **" << std::endl;
    mine.push_back(4);
    their.push_back(4);

    std::cout <<  std::endl << "** size **" << std::endl;
    std::cout << mine.size() << std::endl;
    std::cout << their.size() << std::endl;

    std::cout <<  std::endl << "** show first element **" << std::endl;
    std::cout << mine[0] << std::endl;
    std::cout << their[0] << std::endl;

    return (0);
}