#include <string.h>
#include <iostream>

#include "../tests/test.map.hpp"
#include "../tests/test.vector.hpp"

void	ping(bool is_real_vector = false)
{
	if (is_real_vector)
		std::cout << "Hello world" << std::endl;
	else
		std::cout << "Hello world" << std::endl;
}

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
		if (strcmp(argv[1], "0") == 0)
			ping(is_real_container);
		if (strcmp(argv[1], "1") == 0)
			test_vector_max_size(is_real_container);
	}
	else if (strcmp(argv[1], "map") == 0) {
		if (strcmp(argv[2], "0") == 0)
			test_map_compile(is_real_container);
		if (strcmp(argv[2], "1") == 0)
			test_map_insert(is_real_container);
		if (strcmp(argv[2], "2") == 0)
			test_map_rbegin_and_rend(is_real_container);
	} else {
		return (handl_err_usage("unknow container name"));
	}
	return (0);
}