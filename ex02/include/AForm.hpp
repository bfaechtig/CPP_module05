/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:15:03 by bfaechti          #+#    #+#             */
/*   Updated: 2026/02/05 12:43:44 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

public:
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const class Bureaucrat& bur);
	virtual void execute(const class Bureaucrat& executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif