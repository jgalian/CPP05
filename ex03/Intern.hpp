#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator = ( Intern const & rhs );

		AForm *			makeForm( std::string formType, std::string formTarget );

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		
};

//std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */
