/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:40:29 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/12 10:35:54 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	/* === BUREAUCRAT CREATION === */
	std::cout << "=== Bureaucrat creation ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat intern("Intern", 150);

	std::cout << std::endl;
	std::cout << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;

	/* === SHRUBBERY === */
	std::cout << "\n=== ShrubberyCreationForm ===" << std::endl;
	try {
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;

		intern.signForm(shrub);
		manager.signForm(shrub);
		intern.executeForm(shrub);
		manager.executeForm(shrub);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	/* === ROBOTOMY === */
	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
	try {
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;

		manager.signForm(robot);
		manager.executeForm(robot);
		boss.executeForm(robot);
		boss.executeForm(robot);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	/* === PRESIDENTIAL === */
	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
	try {
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;

		manager.signForm(pardon);
		boss.signForm(pardon);
		manager.executeForm(pardon);
		boss.executeForm(pardon);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	/* === EXECUTE UNSIGNED FORM === */
	std::cout << "\n=== Execute unsigned form ===" << std::endl;
	try {
		RobotomyRequestForm unsignedForm("Target");
		boss.executeForm(unsignedForm);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	/* === INTERN VALID === */
	std::cout << "\n=== Intern: valid forms ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm *f1 = NULL;
		AForm *f2 = NULL;
		AForm *f3 = NULL;

		try {
			f1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
			f2 = someRandomIntern.makeForm("robotomy request", "Bender");
			f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

			if (f1) std::cout << *f1 << std::endl;
			if (f2) std::cout << *f2 << std::endl;
			if (f3) std::cout << *f3 << std::endl;

			if (f1) { boss.signForm(*f1); boss.executeForm(*f1); }
			if (f2) { boss.signForm(*f2); boss.executeForm(*f2); }
			if (f3) { boss.signForm(*f3); boss.executeForm(*f3); }
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		delete f1;
		delete f2;
		delete f3;
	}

	/* === INTERN INVALID === */
	std::cout << "\n=== Intern: unknown form ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm *bad = NULL;

		try {
			bad = someRandomIntern.makeForm("unknown form", "Target");
			if (bad)
				std::cout << *bad << std::endl;
			else
				std::cout << "Form pointer is NULL" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		delete bad;
	}

	std::cout << "\n=== Tests finished ===" << std::endl;
	return 0;
}