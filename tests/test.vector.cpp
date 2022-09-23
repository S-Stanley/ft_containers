#include "test.vector.hpp"

void	test_vector_element_access(bool is_real_vector)
{
	if (is_real_vector) {
		std::vector<int>	vec;

		for (int i = 1; i < 10000; i++)
			vec.push_back(i * 2);
		std::cout << vec[2] << std::endl;
		std::cout << vec.at(1) << std::endl;
		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;
	} else {
		ft::vector<int>	vec;

		for (int i = 1; i < 10000; i++)
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

void	test_vector_equal(bool is_real_container)
{
	if (is_real_container)
	{
		// std::vector<int>	vector_std;
		// std::vector<int>	vector_std_2;

		// vector_std.push_back(42);

		// vector_std_2 = vector_std;

		// std::cout << vector_std.size() << std::endl;
		// std::cout << vector_std_2.size() << std::endl;

		// std::cout << vector_std.at(0) << std::endl;
		// std::cout << vector_std_2.at(0) << std::endl;
	}
	else
	{
		// ft::vector<int>	vector_ft;
		// ft::vector<int>	vector_ft_2;

		// vector_ft.push_back(42);

		// vector_ft_2 = vector_ft;

		// vector_ft.push_back(15);

		// std::cout << vector_ft.size() << std::endl;
		// std::cout << vector_ft_2.size() << std::endl;

		// std::cout << vector_ft.at(0) << std::endl;
		// std::cout << "end of function \n";
		// std::cout << vector_ft_2.at(0) << std::endl;
	}
}

void	test_vector_rbegin_and_rend(bool is_real_container)
{
	if (is_real_container)
	{
		// std::vector<int>	vector_std;

		// vector_std.push_back(24);
		// vector_std.push_back(42);

		// std::vector<int>::reverse_iterator	rit = vector_std.rbegin();

		// while (rit != vector_std.rend())
		// {
		// 	std::cout << *rit << std::endl;
		// 	*rit++;
		// }
	}
	else
	{
		// ft::vector<int>	vector_ft;

		// vector_ft.push_back(24);
		// vector_ft.push_back(42);

		// ft::vector<int>::reverse_iterator	rit = vector_ft.rbegin();

		// while (rit != vector_ft.rend())
		// {
		// 	std::cout << rit << std::endl;
		// 	rit++;
		// }
	}
}

void	test_vector_resize(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;

		vector_std.push_back(42);
		vector_std.push_back(15);
		vector_std.push_back(24);

		vector_std.resize(1);
		std::cout << vector_std.size() << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;

		vector_ft.push_back(42);
		vector_ft.push_back(15);
		vector_ft.push_back(24);

		vector_ft.resize(1);
		std::cout << vector_ft.size() << std::endl;
	}
}

void	test_vector_reserve(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;

		std::cout << vector_std.capacity() << std::endl;
		vector_std.reserve(10);
		std::cout << vector_std.capacity() << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;

		std::cout << vector_ft.capacity() << std::endl;
		vector_ft.reserve(10);
		std::cout << vector_ft.capacity() << std::endl;
	}
}

void	test_vector_assign(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;
		std::vector<int>	vector_std_2;

		vector_std.push_back(42);
		vector_std.push_back(15);
		vector_std.push_back(24);

		vector_std.assign(10, 7);
		std::cout << vector_std.size() << std::endl;
		std::cout << vector_std.at(0) << std::endl;

		vector_std_2.assign(vector_std.begin(), vector_std.end());
		std::cout << vector_std.size() << std::endl;
		std::cout << vector_std.at(0) << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;
		ft::vector<int>	vector_ft_2;

		vector_ft.push_back(42);
		vector_ft.push_back(15);
		vector_ft.push_back(24);

		vector_ft.assign(10, 7);
		std::cout << vector_ft.size() << std::endl;
		std::cout << vector_ft.at(0) << std::endl;

		vector_ft_2.assign(vector_ft.begin(), vector_ft.end());
		std::cout << vector_ft.size() << std::endl;
		std::cout << vector_ft.at(0) << std::endl;
	}
}

void	test_vector_pop_back(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;

		std::cout << vector_std.size() << std::endl;
		vector_std.push_back(42);

		std::cout << vector_std.size() << std::endl;
		vector_std.push_back(15);

		vector_std.pop_back();
		std::cout << vector_std.size() << std::endl;

		vector_std.pop_back();
		std::cout << vector_std.size() << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;

		std::cout << vector_ft.size() << std::endl;
		vector_ft.push_back(42);

		std::cout << vector_ft.size() << std::endl;
		vector_ft.push_back(15);

		vector_ft.pop_back();
		std::cout << vector_ft.size() << std::endl;

		vector_ft.pop_back();
		std::cout << vector_ft.size() << std::endl;
	}
}

void	test_vector_insert(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;
		std::vector<int>	vector_std_2;

		vector_std.insert(vector_std.begin(), 42);
		std::cout << vector_std.size() << std::endl;

		vector_std.insert(vector_std.begin(), 10, 15);
		std::cout << vector_std.size() << std::endl;

		vector_std_2.insert(vector_std_2.begin(), vector_std.begin(), vector_std.end());
		std::cout << vector_std_2.size() << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;
		ft::vector<int>	vector_ft_2;

		vector_ft.insert(vector_ft.begin(), 42);
		std::cout << vector_ft.size() << std::endl;

		vector_ft.insert(vector_ft.begin(), 10, 15);
		std::cout << vector_ft.size() << std::endl;

		vector_ft_2.insert(vector_ft_2.begin(), vector_ft.begin(), vector_ft.end());
		std::cout << vector_ft_2.size() << std::endl;
	}
}

void	test_vector_erase(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;

		vector_std.push_back(42);
		vector_std.push_back(15);
		vector_std.push_back(24);
		std::cout << vector_std.size() << std::endl;

		vector_std.erase(vector_std.begin());
		std::cout << vector_std.size() << std::endl;

		vector_std.erase(vector_std.begin(), vector_std.end());
		std::cout << vector_std.size() << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;

		vector_ft.push_back(42);
		vector_ft.push_back(15);
		vector_ft.push_back(24);
		std::cout << vector_ft.size() << std::endl;

		vector_ft.erase(vector_ft.begin());
		std::cout << vector_ft.size() << std::endl;

		vector_ft.erase(vector_ft.begin(), vector_ft.end());
		std::cout << vector_ft.size() << std::endl;
	}
}

void	test_vector_clear(bool is_real_container)
{
	if (is_real_container)
	{
		std::vector<int>	vector_std;

		vector_std.push_back(42);
		vector_std.push_back(24);

		std::cout << vector_std.size() << std::endl;

		vector_std.clear();
		std::cout << vector_std.size() << std::endl;
	}
	else
	{
		ft::vector<int>	vector_ft;

		vector_ft.push_back(42);
		vector_ft.push_back(24);

		std::cout << vector_ft.size() << std::endl;

		vector_ft.clear();
		std::cout << vector_ft.size() << std::endl;
	}
}