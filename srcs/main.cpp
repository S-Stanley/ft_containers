#include <string.h>
#include <iostream>

#include "../tests/test.map.hpp"
#include "../tests/test.vector.hpp"
#include "../tests/test.pair.hpp"
#include "../tests/test.stack.hpp"

int	handl_err_usage(std::string message = "Unknow error")
{
	std::cout << message << std::endl;
	std::cout << "Usage:" << std::endl;
	std::cout << "./ft_containers [container_name] [test_number] [type (std or ft)]" << std::endl;
	return (1);
}

int     main(int argc, char **argv)
{
	bool is_real_container = false;
	if (argc != 4) {
		return (handl_err_usage("Wrong usage"));
	}
	if (strcmp(argv[3], "std") != 0 && strcmp(argv[3], "ft") != 0) {
		return (handl_err_usage("unknow type"));
	}
	if (strcmp(argv[3], "std") == 0) {
		is_real_container = true;
	}
	if (strcmp(argv[1], "vector") == 0) {
		if (strcmp(argv[2], "0") == 0)
			test_vector_max_size(is_real_container);
		if (strcmp(argv[2], "1") == 0)
			test_vector_allocator(is_real_container);
		if (strcmp(argv[2], "2") == 0)
			test_vector_element_access(is_real_container);
		if (strcmp(argv[2], "3") == 0)
			test_vector(is_real_container);
		if (strcmp(argv[2], "4") == 0)
			test_vector_capacity(is_real_container);
		if (strcmp(argv[2], "5") == 0)
			test_modifiers(is_real_container);
		if (strcmp(argv[2], "6") == 0)
			test_vector_relational_operators(is_real_container);
	}
	else if (strcmp(argv[1], "map") == 0) {
		if (strcmp(argv[2], "0") == 0)
			test_map_compile(is_real_container);
		if (strcmp(argv[2], "1") == 0)
			test_map_insert(is_real_container);
		if (strcmp(argv[2], "2") == 0)
			test_map_rbegin_and_rend(is_real_container);
		if (strcmp(argv[2], "3") == 0)
			test_map_empty(is_real_container);
		if (strcmp(argv[2], "4") == 0)
			test_map_size(is_real_container);
		if (strcmp(argv[2], "5") == 0)
			test_map_clear(is_real_container);
		if (strcmp(argv[2], "6") == 0)
			test_map_count(is_real_container);
		if (strcmp(argv[2], "7") == 0)
			test_map_erase(is_real_container);
		if (strcmp(argv[2], "8") == 0)
			test_key_comp(is_real_container);
		if (strcmp(argv[2], "9") == 0)
			test_map_lower_bound(is_real_container);
		if (strcmp(argv[2], "10") == 0)
			test_map_sorted(is_real_container);
		if (strcmp(argv[2], "11") == 0)
			test_map_iterator(is_real_container);
		if (strcmp(argv[2], "12") == 0)
			test_map_upper_bound(is_real_container);
		if (strcmp(argv[2], "13") == 0)
			test_map_find(is_real_container);
		if (strcmp(argv[2], "14") == 0)
			test_map_element_access(is_real_container);
		if (strcmp(argv[2], "15") == 0)
			test_map_operator_equal(is_real_container);
		if (strcmp(argv[2], "16") == 0)
			test_map_swap(is_real_container);
		if (strcmp(argv[2], "17") == 0)
			test_map_equal_range(is_real_container);
		if (strcmp(argv[2], "18") == 0)
			test_map_value_comp(is_real_container);
		if (strcmp(argv[2], "19") == 0)
			test_map_insert_with_range(is_real_container);
	} else if (strcmp(argv[1], "others") == 0) {
		if (strcmp(argv[2], "0") == 0)
			test_pair(is_real_container);
		if (strcmp(argv[2], "1") == 0)
			test_make_pair(is_real_container);
		if (strcmp(argv[2], "2") == 0)
			test_is_integral(is_real_container);
		if (strcmp(argv[2], "3") == 0)
			test_enable_if(is_real_container);
		if (strcmp(argv[2], "4") == 0)
			test_equal(is_real_container);
	} else if (strcmp(argv[1], "stack") == 0){
		if (strcmp(argv[2], "0") == 0)
			compile_stack(is_real_container);
		if (strcmp(argv[2], "1") == 0)
			stack_empty(is_real_container);
		if (strcmp(argv[2], "2") == 0)
			stack_size(is_real_container);
		if (strcmp(argv[2], "3") == 0)
			stack_top(is_real_container);
		if (strcmp(argv[2], "4") == 0)
			stack_push(is_real_container);
		if (strcmp(argv[2], "5") == 0)
			stack_pop(is_real_container);
		if (strcmp(argv[2], "6") == 0)
			test_stack_relational_operators(is_real_container);
	} else {
		return (handl_err_usage("unknow container name"));
	}
	return (0);
}
