/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:40:29 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/11 16:45:13 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	std::cout << "=== TEST 1: ShrubberyCreationForm - Signing Failure (Grade Too Low) ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub("home");
		intern.signForm(shrub);
		std::cout << shrub << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: ShrubberyCreationForm - Signing Success ===" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 50);
		ShrubberyCreationForm shrub("home");
		manager.signForm(shrub);
		std::cout << shrub << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: ShrubberyCreationForm - Execute Unsigned Form ===" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 50);
		ShrubberyCreationForm shrub("garden");
		manager.executeForm(shrub);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: ShrubberyCreationForm - Execute with Grade Too Low ===" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 50);
		ShrubberyCreationForm shrub("yard");
		manager.signForm(shrub);
		Bureaucrat lowGrade("LowGrade", 140);
		lowGrade.executeForm(shrub);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 5: ShrubberyCreationForm - Successful Execution ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("success");
		boss.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: RobotomyRequestForm - Successful Signing and Execution ===" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 40);
		RobotomyRequestForm robot("Bender");
		manager.signForm(robot);
		manager.executeForm(robot);
		manager.executeForm(robot);
		manager.executeForm(robot);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 7: RobotomyRequestForm - Execute with Grade Too Low ===" << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 50);
		RobotomyRequestForm robot("Robot");
		lowGrade.signForm(robot);
		Bureaucrat veryLow("VeryLow", 150);
		veryLow.executeForm(robot);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 8: PresidentialPardonForm - Signing Failure ===" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 50);
		PresidentialPardonForm pardon("Arthur Dent");
		manager.signForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 9: PresidentialPardonForm - Successful Signing and Execution ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Prisoner X");
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 10: PresidentialPardonForm - Execute with Grade Too Low ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Prisoner Y");
		boss.signForm(pardon);
		Bureaucrat mid("Mid", 10);
		mid.executeForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}