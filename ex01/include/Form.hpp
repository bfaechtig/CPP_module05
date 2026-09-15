/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:15:03 by bfaechti          #+#    #+#             */
/*   Updated: 2026/02/05 12:28:53 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

public:
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const class Bureaucrat& bur);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif