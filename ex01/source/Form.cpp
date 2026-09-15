/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:12:27 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/11 15:29:36 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/* ===== Constructor ===== */
Form::Form(std::string name, int signGrade, int executeGrade) : 
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_executeGrade(executeGrade) 
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout	<< "Form [" << _name << "] created with sign grade "
				<< _signGrade << " and execute grade "
				<< _executeGrade << std::endl;
}

/* ===== Copy Constructor ===== */
Form::Form(const Form &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_signGrade(other._signGrade),
	_executeGrade(other._executeGrade)
{
	*this = other;
	std::cout << "Form [" << _name << "] copied" << std::endl;
}

/* ===== Assignment Operator ===== */
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	std::cout << "Form [" << _name << "] operator= called" << std::endl;
	return (*this);
}

/* ===== Destructor ===== */
Form::~Form()
{
	std::cout << "Form [" << _name << "] destroyed" << std::endl;
}

/* ===== Getters ===== */
std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecuteGrade() const
{
	return (_executeGrade);
}

/* ===== Functions ===== */
void Form::beSigned(const class Bureaucrat& bur) {
	if (bur.getGrade() > _signGrade)
		throw Form::GradeTooHighException();
	_isSigned = true;
}

/* ===== Exception Classes ===== */
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

/* ===== Insertion Operator ===== */
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form [" << form.getName() 
	   << "], Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade Required: " << form.getSignGrade()
	   << ", Execute Grade Required: " << form.getExecuteGrade();
	return (os);
}