#include <iostream>
#include "./test.map.hpp"
#include "../srcs/pair.hpp"

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

void    test_is_integral(bool is_real_container)
{
    if (is_real_container) {
        std::cout << std::is_integral<char>::value << std::endl;
        std::cout << std::is_integral<float>::value << std::endl;
    } else {
        std::cout << ft::is_integral<char>::value << std::endl;
        std::cout << ft::is_integral<float>::value << std::endl;
    }
}

bool function_for_enable_if(typename std::enable_if<true, bool>::type = true)
{
    return (true);
}

bool function_for_enable_if_ft(typename ft::enable_if<true, bool>::type = true)
{
    return (true);
}

void    test_enable_if(bool is_real_container)
{
    if (is_real_container) {
        std::cout << function_for_enable_if(false) << std::endl;
        std::cout << function_for_enable_if() << std::endl;
    } else {
        std::cout << function_for_enable_if_ft(false) << std::endl;
        std::cout << function_for_enable_if_ft() << std::endl;
    }
}