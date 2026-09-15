/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:40:29 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/11 16:19:00 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main( void )
{
	std::cout << "=== TEST 1: Form Creation and Getters ===" << std::endl;
	try
	{
		Form f1("Tax Form", 20, 30);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== TEST 2: Form Signing - Valid Case ===" << std::endl;
	try
	{
		Bureaucrat b1("Chris", 24);
		Form f2("Contract", 25, 50);
		std::cout << "Before signing: " << f2 << std::endl;
		b1.signForm(f2);
		std::cout << "After signing: " << f2 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== TEST 3: Form Signing - Grade Too Low ===" << std::endl;
	try
	{
		Bureaucrat b3("Basile", 62);
		Form f3("Important Document", 5, 10);
		std::cout << "Before attempt: " << f3 << std::endl;
		b3.signForm(f3);
		std::cout << "After attempt: " << f3 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== TEST 4: Form with Invalid Grades in Constructor ===" << std::endl;
	try
	{
		Form f4("Invalid Form 1", 0, 50);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Form f5("Invalid Form 2", 25, 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== TEST 5: Successful Signing with Grade 1 ===" << std::endl;
	try
	{
		Bureaucrat b2("Theo", 7);
		Form f6("Promotion Form", 1, 1);
		std::cout << "Form Info: " << f6 << std::endl;
		b2.signForm(f6);
		std::cout << "After signing: " << f6 << std::endl;
		b2.upGrade(6);
		std::cout << "[" << b2.getName() << "] up is grade, is now [" << b2.getGrade() << "]" << std::endl;
		b2.signForm(f6);
		std::cout << "Re After signing: " << f6 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== TEST 6: Multiple Signing Attempts ===" << std::endl;
	try
	{
		Bureaucrat b1("Alice", 60);
		Bureaucrat b2("Bob", 40);
		Form f7("Multi-Sign Form", 50, 60);
		std::cout << "Form: " << f7 << std::endl;
		std::cout << "\nAttempt 1 - Bureaucrat with grade 60:" << std::endl;
		b1.signForm(f7);
		std::cout << "\nAttempt 2 - Bureaucrat with grade 40:" << std::endl;
		b2.signForm(f7);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	return (0);
}