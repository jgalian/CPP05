#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat bobby("Bobby", 5);
		bobby.incrementGrade();
		std::cout << bobby << std::endl;
		bobby.decrementGrade();
		bobby.decrementGrade();
		std::cout << bobby << std::endl;
		Bureaucrat marvin("Marvin", 150);
		std::cout << marvin << std::endl;
		marvin.setGrade(140);
		std::cout << marvin << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "///////////////////////////////////////";
	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat johnny("Johnny", 1);
		johnny.incrementGrade();
		std::cout << johnny << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
