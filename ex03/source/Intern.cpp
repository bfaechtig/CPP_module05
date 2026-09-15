/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:30:39 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/12 10:29:56 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ===== Constructor ===== */
Intern::Intern(/* args */) {
	std::cout << "Intern default constructor called" << std::endl;
}

/* ===== Copy constructor ===== */
Intern::Intern(const Intern &copy) {
	*this = copy;
	std::cout << "Intern copy constructor called" << std::endl;
}

/* ===== Copy assignment operator ===== */
Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		// No data members to copy
	}
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

/* ===== Destructor ===== */
Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

/* ===== Public Functions ===== */
static AForm *createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }
static AForm *createRobotomy(std::string target) { return new RobotomyRequestForm(target); }
static AForm *createPresidential(std::string target) { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(std::string) = {createShrubbery, createRobotomy, createPresidential};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern cannot create " << formName << " because it is unknown" << std::endl;
	return (NULL);
}