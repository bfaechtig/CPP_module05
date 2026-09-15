/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:16:26 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/11 16:41:50 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

/* ===== Constructor ===== */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm(target, 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm [" << _target << "] created" << std::endl;
}

/* ===== Copy Constructor ===== */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy),
	_target(copy._target)
{
	std::cout << "ShrubberyCreationForm [" << _target << "] copied" << std::endl;
}

/* ===== Assignment Operator ===== */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/* ===== Destructor ===== */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm [" << _target << "] destroyed" << std::endl;
}

/* ===== Execute Method ===== */
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw std::runtime_error("Form is not signed");
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooHighException();

	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return ;
	}

	file << "      ^      " << std::endl;
	file << "     ^^^     " << std::endl;
	file << "    ^^^^^    " << std::endl;
	file << "   ^^^^^^^   " << std::endl;
	file << "  ^^^^^^^^^  " << std::endl;
	file << " ^^^^^^^^^^^ " << std::endl;
	file << "^^^^^^^^^^^^^" << std::endl;
	file << "     |||     " << std::endl;

	file.close();
	std::cout << "[" << executor.getName() << "] executed " << this->getName() << " - Shrubbery written to " << filename << std::endl;
}
