/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:12:27 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/11 16:29:31 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

/* ===== Constructor ===== */
AForm::AForm(std::string name, int signGrade, int executeGrade) : 
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_executeGrade(executeGrade) 
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout	<< "AForm [" << _name << "] created with sign grade "
				<< _signGrade << " and execute grade " 
				<< _executeGrade << std::endl;
}

/* ===== Copy Constructor ===== */
AForm::AForm(const AForm &copy) :
	_name(copy._name),
	_isSigned(copy._isSigned),
	_signGrade(copy._signGrade),
	_executeGrade(copy._executeGrade)
{
	*this = copy;
	std::cout << "AForm [" << _name << "] copied" << std::endl;
}

/* ===== Assignment Operator ===== */
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	std::cout << "AForm [" << _name << "] operator= called" << std::endl;
	return (*this);
}

/* ===== Destructor ===== */
AForm::~AForm()
{
	std::cout << "AForm [" << _name << "] destroyed" << std::endl;
}

/* ===== Getters ===== */
std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

/* ===== Functions ===== */
void AForm::beSigned(const class Bureaucrat &bur) {
	if (bur.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

/* ===== Exception Classes ===== */
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low");
}

/* ===== Insertion Operator ===== */
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm: [" << form.getName() 
	   << "], Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade Required: " << form.getSignGrade()
	   << ", Execute Grade Required: " << form.getExecuteGrade();
	return (os);
}
