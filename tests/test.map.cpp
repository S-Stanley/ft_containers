#include "test.map.hpp"

void    test_map_compile(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, int>    map_std;

        map_std["cpp"] = 7;
        map_std["ts"] = 8;
        std::cout << map_std["cpp"] << std::endl;
    } else {
        ft::map<std::string, int>     map_ft;

        map_ft.insert("cpp", 7);
        map_ft.insert("ts", 8);
        std::cout << map_ft["cpp"] << std::endl;
    }
}