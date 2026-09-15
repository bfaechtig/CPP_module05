/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:16:26 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/11 16:41:13 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

/* ===== Constructor ===== */
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm(target, 25, 5),
	_target(target)
{
	std::cout << "PresidentialPardonForm [" << _target << "] created" << std::endl;
}

/* ===== Copy Constructor ===== */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
	AForm(copy),
	_target(copy._target)
{
	std::cout << "PresidentialPardonForm [" << _target << "] copied" << std::endl;
}

/* ===== Assignment Operator ===== */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/* ===== Destructor ===== */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm [" << _target << "] destroyed" << std::endl;
}

/* ===== Execute Method ===== */
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw std::runtime_error("Form is not signed");
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooHighException();

	std::cout << "[" << _target << "] has been pardoned by Zaphod Beeblebrox." << std::endl;
}