#include "test.vector.hpp"

void	test_vector_element_access(bool is_real_vector)
{
	if (is_real_vector) {
		std::vector<int>	vec;

		for (int i = 1; i < 7; i++)
			vec.push_back(i * 2);
		std::cout << vec[2] << std::endl;
		std::cout << vec.at(1) << std::endl;
		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;
	} else {
		ft::vector<int>	vec;

		for (int i = 1; i < 7; i++)
			vec.push_back(i * 2);
		std::cout << vec[2] << std::endl;
		std::cout << vec.at(1) << std::endl;
		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;
	}
}

void	test_vector_capacity(bool is_real_vector)
{
	if (is_real_vector) {
		std::vector<int>	vec;

		srand(time(NULL));
		for (int i = 0; i < 5; i++)
			vec.push_back(i);

		std::cout << vec.empty() << std::endl;
		std::cout << vec.size() << std::endl;
		vec.reserve(10);
		std::cout << vec.size() << std::endl;
		vec.resize(10, 42);
		std::cout << vec.size() << std::endl;
	} else {
		ft::vector<int>		vec;

		srand(time(NULL));
		for (int i = 0; i < 5; i++)
			vec.push_back(i);

		std::cout << vec.empty() << std::endl;
		std::cout << vec.size() << std::endl;
		vec.reserve(10);
		std::cout << vec.size() << std::endl;
		vec.resize(10, 42);
		std::cout << vec.size() << std::endl;
	}
}

void    test_modifiers(bool is_real_vector)
{
	if (is_real_vector)
	{
    	std::vector<int>    vec;
    	vec.push_back(42);
		vec.push_back(42);
	}
	else
	{
        ft::vector<int>     vec;
		vec.push_back(42);
		vec.push_back(42);
	}
}

void	test_vector_max_size(bool is_real_vector)
{
	if (is_real_vector)
	{
		std::vector<char>	vector_char;
		std::vector<int>	vector_int;
		std::vector<unsigned int>	vector_unsigned_int;
		std::vector<long long>	vector_long_long;

		std::cout << vector_long_long.max_size() << std::endl;
		std::cout << vector_int.max_size() << std::endl;
		std::cout << vector_char.max_size() << std::endl;
		std::cout << vector_unsigned_int.max_size() << std::endl;
	}
	else
	{
		ft::vector<char>	vector_char;
		ft::vector<int>	vector_int;
		ft::vector<unsigned int>	vector_unsigned_int;
		ft::vector<long long>	vector_long_long;

		std::cout << vector_long_long.max_size() << std::endl;
		std::cout << vector_int.max_size() << std::endl;
		std::cout << vector_char.max_size() << std::endl;
		std::cout << vector_unsigned_int.max_size() << std::endl;
	}
}

void	test_vector_allocator(bool is_real_container)
{
	if (is_real_container) {
		std::vector<int>	vector_std;
		int					*p;

		p = vector_std.get_allocator().allocate(5);
        std::cout << sizeof(std::vector<int>::value_type) * 5 << std::endl;
		vector_std.get_allocator().deallocate(p, 5);
	} else {
		ft::vector<int>	vector_ft;
		int					*p;

		p = vector_ft.get_allocator().allocate(5);
        std::cout << sizeof(ft::vector<int>::value_type) * 5 << std::endl;
		vector_ft.get_allocator().deallocate(p, 5);
	}
}

void	test_vector_relational_operators(bool is_real_container)
{
	if (is_real_container){
		std::vector<int>	vector_std;
		std::vector<int>	vector_std_2;

		vector_std.push_back(5);
		vector_std.push_back(10);
		vector_std_2.push_back(5);

		std::cout << (vector_std == vector_std_2) << std::endl;
		std::cout << (vector_std != vector_std_2) << std::endl;
		std::cout << (vector_std < vector_std_2) << std::endl;
		std::cout << (vector_std <= vector_std_2) << std::endl;
		std::cout << (vector_std > vector_std_2) << std::endl;
		std::cout << (vector_std >= vector_std_2) << std::endl;

		vector_std_2.push_back(10);

		std::cout << (vector_std == vector_std_2) << std::endl;
		std::cout << (vector_std != vector_std_2) << std::endl;
		std::cout << (vector_std < vector_std_2) << std::endl;
		std::cout << (vector_std <= vector_std_2) << std::endl;
		std::cout << (vector_std > vector_std_2) << std::endl;
		std::cout << (vector_std >= vector_std_2) << std::endl;
	} else {
		ft::vector<int>	vector_ft;
		ft::vector<int>	vector_ft_2;

		vector_ft.push_back(5);
		vector_ft.push_back(10);
		vector_ft_2.push_back(5);

		std::cout << (vector_ft == vector_ft_2) << std::endl;
		std::cout << (vector_ft != vector_ft_2) << std::endl;
		std::cout << (vector_ft < vector_ft_2) << std::endl;
		std::cout << (vector_ft <= vector_ft_2) << std::endl;
		std::cout << (vector_ft > vector_ft_2) << std::endl;
		std::cout << (vector_ft >= vector_ft_2) << std::endl;

		vector_ft_2.push_back(10);

		std::cout << (vector_ft == vector_ft_2) << std::endl;
		std::cout << (vector_ft != vector_ft_2) << std::endl;
		std::cout << (vector_ft < vector_ft_2) << std::endl;
		std::cout << (vector_ft <= vector_ft_2) << std::endl;
		std::cout << (vector_ft > vector_ft_2) << std::endl;
		std::cout << (vector_ft >= vector_ft_2) << std::endl;
	}
}

void	test_vector_iterator_and_const_iterator(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;

		vector_std.push_back(5);
		vector_std.push_back(10);

		std::vector<int>::iterator			it = vector_std.begin();
		std::vector<int>::const_iterator	it_end = vector_std.end();

		while (it != it_end)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
	else
	{
		ft::vector<int>	vector_ft;

		vector_ft.push_back(5);
		vector_ft.push_back(10);

		ft::vector<int>::iterator			it = vector_ft.begin();
		ft::vector<int>::const_iterator	it_end = vector_ft.end();

		while ((*it) != (*it_end))
		{
			std::cout << (*it) << std::endl;
			(*it)++;
		}
	}
}

void	test_vector_swap(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;
		std::vector<int>	vector_std_2;

		vector_std.push_back(42);
		vector_std_2.push_back(24);

		vector_std.swap(vector_std_2);

		std::cout << vector_std[0] << std::endl;
		std::cout << vector_std_2[0] << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;
		ft::vector<int>	vector_ft_2;

		vector_ft.push_back(42);
		vector_ft_2.push_back(24);

		vector_ft.swap(vector_ft_2);

		std::cout << vector_ft[0] << std::endl;
		std::cout << vector_ft_2[0] << std::endl;
	}
}