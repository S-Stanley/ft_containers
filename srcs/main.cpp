#include <iostream>
#include <vector>

#include "vector.hpp"

int     main(void)
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

	return (0);
}