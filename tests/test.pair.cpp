#include <iostream>
#include <vector>

#include "./test.map.hpp"
#include "../srcs/vector.hpp"
#include "../srcs/pair.hpp"

ft::pair<std::string, std::string> create_ft_pair_2(std::string key, std::string value)
{
    ft::pair<std::string, std::string> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}

std::pair<std::string, std::string> create_std_pair_2(std::string key, std::string value)
{
    std::pair<std::string, std::string> to_return;

    to_return.first = key;
    to_return.second = value;
    return (to_return);
}

void    test_pair(bool is_real_container)
{
    if (is_real_container) {
        std::pair<std::string, std::string> std_pair;
        std::pair<unsigned int, std::string> std_pair_2;

        std_pair.first = "Hello";
        std_pair.second = "Word";
        std::cout << std_pair.first << std::endl;
        std::cout << std_pair.second << std::endl;

        std_pair_2.first = 2;
        std_pair_2.second = "two";
        std::cout << std_pair_2.first << std::endl;
        std::cout << std_pair_2.second << std::endl;
    } else {
        ft::pair<std::string, std::string> ft_pair;
        ft::pair<unsigned int, std::string> ft_pair_2;

        ft_pair.first = "Hello";
        ft_pair.second = "Word";
        std::cout << ft_pair.first << std::endl;
        std::cout << ft_pair.second << std::endl;

        ft_pair_2.first = 2;
        ft_pair_2.second = "two";
        std::cout << ft_pair_2.first << std::endl;
        std::cout << ft_pair_2.second << std::endl;
    }
}

void    test_make_pair(bool is_real_container)
{
    if (is_real_container) {
        std::cout << std::make_pair("Hello", "world").first << std::endl;
        std::cout << std::make_pair("Hello", "world").second << std::endl;
    } else {
        std::cout << ft::make_pair("Hello", "world").first << std::endl;
        std::cout << ft::make_pair("Hello", "world").second << std::endl;
    }
}

void    test_equal(bool is_real_container)
{
    if (is_real_container) {
        std::map<std::string, std::string>           map_std;
        std::map<std::string, std::string>::iterator it;

        std::pair<std::string, std::string>     val1 = create_std_pair_2("test", "value test");
        std::pair<std::string, std::string>     val2 = create_std_pair_2("test 1", "value test 1");

        map_std.insert(val1);
        map_std.insert(val2);
        it = map_std.begin();
        std::cout << std::equal(map_std.begin(), map_std.end(), it) << std::endl;
    } else {
        ft::map<std::string, std::string>           map_ft;
        ft::map<std::string, std::string>::iterator it;

        ft::pair<std::string, std::string>     val1 = create_ft_pair_2("test", "value test");
        ft::pair<std::string, std::string>     val2 = create_ft_pair_2("test 1", "value test 1");

        map_ft.insert(val1);
        map_ft.insert(val2);
        it = map_ft.begin();
        std::cout << ft::equal(map_ft.begin(), map_ft.end(), it) << std::endl;
    }
}
