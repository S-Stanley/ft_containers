#include "test.map.hpp"

std::pair<std::string, int> create_std_pair(std::string key, int value)
{
    std::pair<std::string, int> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}

std::pair<std::string, std::string> create_std_pair(std::string key, std::string value)
{
    std::pair<std::string, std::string> to_return;

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
        std::map<std::string, int>    map_std_2;
        std::map<std::string, int>::iterator it;

        map_std.insert(val1);
        map_std.insert(val2);
        it = map_std.end();
        map_std.insert(it, val3);
        std::cout << map_std["cpp"] << std::endl;
        std::cout << map_std["ts"] << std::endl;
        std::cout << map_std["py"] << std::endl;
        map_std_2.insert(map_std.begin(), map_std.end());
        std::cout << map_std_2["cpp"] << std::endl;
        std::cout << map_std_2["ts"] << std::endl;
        std::cout << map_std_2["py"] << std::endl;
    } else {
        ft::map<std::string, int>     map_ft;
        ft::map<std::string, int>     map_ft_2;
        Iterator<int>                   it;

        map_ft.insert(val1);
        map_ft.insert(val2);
        it = map_ft.end();
        map_ft.insert(it, val3);
        std::cout << map_ft["cpp"] << std::endl;
        std::cout << map_ft["ts"] << std::endl;
        std::cout << map_ft["py"] << std::endl;
        map_ft_2.insert(map_ft.begin(), map_ft.end());
        std::cout << map_ft_2["cpp"] << std::endl;
        std::cout << map_ft_2["ts"] << std::endl;
        std::cout << map_ft_2["py"] << std::endl;
    }
}

void    test_map_rbegin_and_rend(bool is_real_container)
{
    std::pair<std::string, std::string>     val1 = create_std_pair("test", "value test");
    std::pair<std::string, std::string>     val2 = create_std_pair("test 1", "value test 1");

    if (is_real_container)
    {
        std::map<std::string, std::string>  map_std;
        std::map<std::string, std::string>  map_std_2;

        map_std.insert(val1);
        map_std.insert(val2);
        std::map<std::string, std::string>::reverse_iterator   rit = map_std.rbegin();
        map_std_2.insert(rit, map_std.rend());
        std::cout << map_std_2["test"] << std::endl;
        std::cout << map_std_2["test 1"] << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;
        ft::map<std::string, std::string>  map_ft_2;

        map_ft.insert(val1);
        map_ft.insert(val2);
        RIterator<std::string>    rit = map_ft.rbegin();
        map_ft_2.insert(rit, map_ft.rend());
        std::cout << map_ft_2["test"] << std::endl;
        std::cout << map_ft_2["test 1"] << std::endl;
    }
}

void    test_map_empty(bool is_real_container)
{
    std::pair<std::string, std::string> val = create_std_pair("hello", "world");

    if (is_real_container) {
        std::map<std::string, std::string>  map_std;

        std::cout << map_std.empty() << std::endl;
        map_std.insert(val);
        std::cout << map_std.empty() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;

        std::cout << map_ft.empty() << std::endl;
        map_ft.insert(val);
        std::cout << map_ft.empty() << std::endl;
    }
}

void    test_map_size(bool is_real_container)
{
    std::pair<std::string, std::string> val = create_std_pair("hello", "world");
    std::pair<std::string, std::string> val1 = create_std_pair("container", "map");

    if (is_real_container) {
        std::map<std::string, std::string>  map_std;

        std::cout << map_std.size() << std::endl;
        map_std.insert(val);
        std::cout << map_std.size() << std::endl;
        map_std.insert(val1);
        std::cout << map_std.size() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;

        std::cout << map_ft.size() << std::endl;
        map_ft.insert(val);
        std::cout << map_ft.size() << std::endl;
        map_ft.insert(val1);
        std::cout << map_ft.size() << std::endl;
    }
}

void    test_map_clear(bool is_real_container)
{
    std::pair<std::string, std::string> val = create_std_pair("hello", "world");
    std::pair<std::string, std::string> val1 = create_std_pair("container", "map");

    if (is_real_container) {
        std::map<std::string, std::string>  map_std;

        map_std.insert(val);
        map_std.insert(val1);
        std::cout << map_std.size() << std::endl;
        map_std.clear();
        std::cout << map_std.size() << std::endl;
    } else {
        ft::map<std::string, std::string>  map_ft;

        map_ft.insert(val);
        map_ft.insert(val1);
        std::cout << map_ft.size() << std::endl;
        map_ft.clear();
        std::cout << map_ft.size() << std::endl;
    }
}