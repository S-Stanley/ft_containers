#ifndef TEST_VECTOR_CPP
# define TEST_VECTOR_CPP

#include <vector>
#include <limits>
#include <cmath>
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <algorithm>

#include "../srcs/vector.hpp"
#include "../srcs/pair.hpp"

void	test_vector_capacity(bool is_real_vector);
void	test_vector_element_access(bool is_real_vector);
void    test_modifiers(bool is_real_vector = false);
void	test_vector_max_size(bool is_real_vector = false);
void	test_vector_allocator(bool is_real_container);
void    test_vector_relational_operators(bool is_real_container);
void	test_vector_iterator_and_const_iterator(bool is_real_container);
void	test_vector_swap(bool is_real_container);
void	test_vector_equal(bool is_real_container);
void	test_vector_resize(bool is_real_container);
void	test_vector_reserve(bool is_real_container);
void	test_vector_assign(bool is_real_container);
void	test_vector_pop_back(bool is_real_container);
void	test_vector_insert(bool is_real_container);
void	test_vector_erase(bool is_real_container);
void	test_vector_clear(bool is_real_container);
void	test_vector_rbegin_and_rend(bool is_real_container);

#endif
