#ifndef TEST_MAP_CPP
#define TEST_MAP_CPP

#include <iostream>
#include <map>

#include "../srcs/map.hpp"
#include "../srcs/reverse_iterator.hpp"

void    test_map_compile(bool is_real_container);
void    test_map_insert(bool is_real_container);
void    test_map_rbegin_and_rend(bool is_real_container);
void    test_map_empty(bool is_real_container);
void    test_map_size(bool is_real_container);
void    test_map_clear(bool is_real_container);
void    test_map_count(bool is_real_container);
void    test_map_erase(bool is_real_container);
void    test_key_comp(bool is_real_container);
void    test_map_lower_bound(bool is_real_container);
void    test_map_sorted(bool is_real_container);
void    test_map_iterator(bool is_real_container);

#endif