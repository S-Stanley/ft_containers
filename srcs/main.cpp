#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <algorithm>

#include "vector.hpp"

void	test_vector_iterators(void)
{
	ft::vector<int>		mine;
	std::vector<int>	their;


	srand(time(NULL));
	for (int i = 0; i < 5; i++){
		int random = rand() % 42;
		mine.push_back(random * i + random);
		their.push_back(random * i + random);
	}

	for (int i = 0; i < 5; i++){
		std::cout << "mine: " << mine[i] << " their: " << their[i] << std::endl;
	}

	Iterator<int>		it;
	it = mine.begin();
	while (it < mine.end())
	{
		std::cout << it << std::endl;
		it++;
	}
}

void	test_vector_element_access(void)
{
	ft::vector<int>	mine;
	std::vector<int> their;

	for (int i = 1; i < 7; i++)
	{
		mine.push_back(i * 2);
		their.push_back(i * 2);
	}

	std::cout << "Elements access" << std::endl << std::endl;
	std::cout << mine[2] << " " << their[2] << std::endl;
	std::cout << mine.at(1) << " " << their.at(1) << std::endl;
	std::cout << mine.front() << " " << their.front() << std::endl;
	std::cout << mine.back() << " " << their.back() << std::endl;
}

void	test_vector(void)
{
	ft::vector<int>     mine;
	std::vector<int>    their;

	std::cout << "** size **" << std::endl;
	std::cout << mine.size() << std::endl;
	std::cout << their.size() << std::endl;

	std::cout <<  std::endl << "** push back: 4 **" << std::endl;
	mine.push_back(4);
	their.push_back(4);

	std::cout <<  std::endl << "** size **" << std::endl;
	std::cout << mine.size() << std::endl;
	std::cout << their.size() << std::endl;

	std::cout <<  std::endl << "** show first element **" << std::endl;
	std::cout << mine[0] << std::endl;
	std::cout << their[0] << std::endl;

	std::cout << "** push back: 42 **" << std::endl;
	mine.push_back(42);
	their.push_back(42);
	std::cout << "** push back: 15 **" << std::endl;
	mine.push_back(15);
	their.push_back(15);
	std::cout << "** push back: 3 **" << std::endl;
	mine.push_back(3);
	their.push_back(3);
	std::cout << "** push back: 24 **" << std::endl;
	mine.push_back(24);
	their.push_back(24);

	std::cout <<  std::endl << "** print value of mine and their **" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << mine[i] << " " << their[i] << std::endl;

	std::cout <<  std::endl << "** erase begin **" << std::endl;
	mine.erase(mine.begin());
	their.erase(their.begin());

	std::cout <<  std::endl << "** print value of mine and their **" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << mine[i] << " " << their[i] << std::endl;

	std::cout <<  std::endl << "** clear and push 42 then 15 **" << std::endl;
	mine.clear();
	mine.push_back(42);
	mine.push_back(15);
	their.clear();
	their.push_back(42);
	their.push_back(15);

	std::cout <<  std::endl << "** size **" << std::endl;
	std::cout << mine.size() << std::endl;
	std::cout << their.size() << std::endl;

	std::cout << "** pop back **" << std::endl;
	mine.pop_back();
	their.pop_back();

	std::cout <<  std::endl << "** size **" << std::endl;
	std::cout << mine.size() << std::endl;
	std::cout << their.size() << std::endl;

	std::cout <<  std::endl << "** print value of mine and their **" << std::endl;
	for (int i = 0; i < 1; i++)
		std::cout << mine[i] << " " << their[i] << std::endl;
}

void	test_vector_capacity(void)
{
	ft::vector<int>		mine;
	std::vector<int>	their;


	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 42;
		mine.push_back(random * i + random);
		their.push_back(random * i + random);
	}

	std::cout << "Max size: " << mine.max_size() << " " << their.max_size() << std::endl << std::endl;
	std::cout << "Empty: " << mine.empty() << " " << their.empty() << std::endl << std::endl;
	std::cout << "Capacity: " << mine.capacity() << " " << their.capacity() << std::endl << std::endl;

	std::cout << "** Reserve **" << std::endl;
	mine.reserve(10);
	their.reserve(10);
	std::cout << std::endl;

	std::cout << "Capacity: " << mine.capacity() << " " << their.capacity() << std::endl << std::endl;

	std::cout << "** Resize **" << std::endl;
	mine.resize(10, 42);
	their.resize(10, 42);
	std::cout << std::endl;

	std::cout << "Capacity: " << mine.capacity() << " " << their.capacity() << std::endl << std::endl;
}

int     main(void)
{
	// test_vector_iterators();
	test_vector_element_access();
	test_vector_capacity();
	return (0);
}