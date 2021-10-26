#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() :
	_name("Default_form"),
	_signed(0),
	_gradeRequiredToSignIt(150),
	_gradeRequiredToExecuteIt(150)
{
}

Form::Form( std::string const name, unsigned const int gradeRequiredToSignIt, unsigned const int gradeRequiredToExecuteIt ) :
	_name(name),
	_signed(0),
	_gradeRequiredToSignIt(gradeRequiredToSignIt),
	_gradeRequiredToExecuteIt(gradeRequiredToExecuteIt)
{
	if ((int)gradeRequiredToSignIt < 0 || (int)gradeRequiredToExecuteIt < 0)
		throw Form::NotUnsignedNumberException();
	if (gradeRequiredToSignIt == 0 || gradeRequiredToExecuteIt == 0)
		throw Form::GradeTooHighException();
	if (gradeRequiredToSignIt > 150 || gradeRequiredToExecuteIt > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form & src ) :
	_name(src._name),
	_signed(src._signed),
	_gradeRequiredToSignIt(src._gradeRequiredToSignIt),
	_gradeRequiredToExecuteIt(src._gradeRequiredToExecuteIt)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator = ( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &		operator << ( std::ostream & o, Form const & i )
{
	std::string status;

	if (i.getSigned())
		status = " has been signed by a bureaucrat with grade equal or higher than ";
	else
		status = " is waiting to be signed  by a bureaucrat with grade equal or higher than ";
	o << i.getName() << status << i.getGradeRequiredToSignIt();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			Form::beSigned( const Bureaucrat & bureaucrat )
{
	if (this->getSigned())
	{
		std::cout << this->getName() << " is already signed" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() <= this->getGradeRequiredToSignIt())
		this->_signed = 1;
	bureaucrat.signForm(*this);
}

const char *		Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char *		Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *		Form::NotUnsignedNumberException::what() const throw()
{
	return ("NotUnsignedNumberException");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	Form::getName( void ) const
{
	return (this->_name);
}

bool				Form::getSigned( void ) const
{
	return (this->_signed);
}

unsigned int		Form::getGradeRequiredToSignIt( void ) const
{
	return (this->_gradeRequiredToSignIt);
}

unsigned int 		Form::getGradeRequiredToExecuteIt( void ) const
{
	return (this->_gradeRequiredToExecuteIt);
}


/* ************************************************************************** */
