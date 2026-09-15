/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:16:26 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/12 10:25:15 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

/* ===== Constructor ===== */
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm(target, 72, 45),
	_target(target)
{
	std::cout << "RobotomyRequestForm " << _target << " created" << std::endl;
}

/* ===== Copy Constructor ===== */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
	AForm(copy),
	_target(copy._target)
{
	std::cout << "RobotomyRequestForm " << _target << " copied" << std::endl;
}

/* ===== Assignment Operator ===== */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/* ===== Destructor ===== */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _target << " destroyed" << std::endl;
}

/* ===== Execute Method ===== */
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooHighException();
	if (!this->getIsSigned())
		throw std::runtime_error("Form is not signed");

	std::cout << "*Drilling Noises*" << std::endl;

	int n = std::rand() % 100;

	if (n < 50)
		std::cout << _target << " successfully robotomized." << std::endl;
	else
		std::cout << "Robotomized failed." << std::endl;
}