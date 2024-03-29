#ifndef TEST_MAP_CPP
#define TEST_MAP_CPP

#include <iostream>
#include <map>

#include "../srcs/map.hpp"
#include "../srcs/reverse_iterator.hpp"
#include "../srcs/pair.hpp"

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
void    test_map_upper_bound(bool is_real_container);
void    test_map_find(bool is_real_container);
void    test_map_element_access(bool is_real_container);
void    test_map_operator_equal(bool is_real_container);
void    test_map_swap(bool is_real_container);
void    test_map_equal_range(bool is_real_container);
void    test_map_value_comp(bool is_real_container);
void    test_map_max_size(bool is_real_container);
void    test_map_insert_with_range(bool is_real_container);
void    test_iterator_and_const_iterator(bool is_real_container);
void    test_iterator_map_swap(bool is_real_container);
void    test_map_never_have_twice_the_same_key(bool is_real_container);
void    test_map_iterator_after_insert(bool is_real_container);
void    test_map_iterator_after_erase(bool is_real_container);

#endif