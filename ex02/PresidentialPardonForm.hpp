#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

		std::string	const	_target;

		PresidentialPardonForm();

	public:

		PresidentialPardonForm( std::string const target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &	operator = ( PresidentialPardonForm const & rhs );

		void			concreteExecution( void ) const;
		
};

//std::ostream &			operator << ( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */
