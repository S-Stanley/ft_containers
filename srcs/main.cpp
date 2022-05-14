#include "../tests/test.vector.hpp"
#include <string.h>
#include <iostream>

void	ping(bool is_real_vector = false)
{
	if (is_real_vector)
		std::cout << "Hello world" << std::endl;
	else
		std::cout << "Hello world" << std::endl;
}


int     main(int argc, char **argv)
{
	bool is_real_vector = false;
	if (argc != 2 && argc != 3)
	{
		std::cout << "Wrong Usage" << std::endl;
		std::cout << "./ft_containers [test_number] [using std (optional)]" << std::endl;
		return (1);
	}
	if (argc == 3) {
		if (strcmp(argv[2], "std") == 0) {
			is_real_vector = true;
		}
	}
	if (strcmp(argv[1], "0") == 0)
		ping(is_real_vector);
	if (strcmp(argv[1], "1") == 0)
		test_vector_max_size(is_real_vector);
	return (0);
}