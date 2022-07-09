#include <iostream>
#include <vector>

#include "./test.map.hpp"
#include "../srcs/vector.hpp"
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

// bool function_for_enable_if(typename std::enable_if<true, bool>::type = true)
// {
//     return (true);
// }

// bool function_for_enable_if_ft(typename ft::enable_if<true, bool>::type = true)
// {
//     return (true);
// }

// void    test_enable_if(bool is_real_container)
// {
//     if (is_real_container) {
//         std::cout << function_for_enable_if(false) << std::endl;
//         std::cout << function_for_enable_if() << std::endl;
//     } else {
//         std::cout << function_for_enable_if_ft(false) << std::endl;
//         std::cout << function_for_enable_if_ft() << std::endl;
//     }
// }

void    test_equal(bool is_real_container)
{
    if (is_real_container) {
        std::vector<int>            vector_std;
        std::vector<int>::iterator  it;

        vector_std.push_back(42);
        vector_std.push_back(42);
        vector_std.push_back(42);
        it = vector_std.begin();
        it++;
        std::cout << std::equal(vector_std.begin(), vector_std.end(), it) << std::endl;
    } else {
        ft::vector<int>            vector_ft;
        ft::vector<int>::iterator  it;

        vector_ft.push_back(42);
        vector_ft.push_back(42);
        vector_ft.push_back(42);
        it = vector_ft.begin();
        (*it)++;
        std::cout << std::equal(vector_ft.begin(), vector_ft.end(), it) << std::endl;
    }
}