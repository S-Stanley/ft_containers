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

void	test_vector_capacity(void);
void	test_vector(void);
void	test_vector_element_access(void);
void	test_vector_iterators(void);
void    test_modifiers(bool is_real_vector = false);
void	test_vector_max_size(bool is_real_vector = false);

#endif