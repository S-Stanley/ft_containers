#include "test.map.hpp"

std::pair<std::string, int> create_std_pair(std::string key, int value)
{
    std::pair<std::string, int> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}

void    test_map_compile(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, int>    map_std;
    } else {
        ft::map<std::string, int>     map_ft;
    }
}

void    test_map_insert(bool is_real_container)
{
    std::cout << "TESTING MAP INSERT" << std::endl;

    std::pair<std::string, int>     val1 = create_std_pair("cpp", 7);
    std::pair<std::string, int>     val2 = create_std_pair("ts", 8);
    std::pair<std::string, int>     val3 = create_std_pair("py", 8);

    if (is_real_container) {
        std::map<std::string, int>    map_std;
        std::map<std::string, int>::iterator it;

        map_std.insert(val1);
        map_std.insert(val2);
        it = map_std.end();
        map_std.insert(it, val3);
        std::cout << map_std["cpp"] << std::endl;
        std::cout << map_std["ts"] << std::endl;
        std::cout << map_std["py"] << std::endl;
    } else {
        ft::map<std::string, int>     map_ft;
        Iterator<int>                   it;

        map_ft.insert(val1);
        map_ft.insert(val2);
        it = map_ft.end();
        map_ft.insert(it, val3);
        std::cout << map_ft["cpp"] << std::endl;
        std::cout << map_ft["ts"] << std::endl;
        std::cout << map_ft["py"] << std::endl;
    }
}