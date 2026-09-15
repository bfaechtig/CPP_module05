/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:40:29 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/12 15:13:19 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main( void )
{
	// Test 1: Creation with valid grades
	std::cout << "=== Test 1: Creation with valid grades ===" << std::endl;
	Bureaucrat b1("Chris", 24);
	Bureaucrat b2("Theo", 7);
	Bureaucrat b3("Basile", 62);

	std::cout << std::endl;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	// Test 2: upGrade and downGrade (normal operations)
	std::cout << std::endl << "=== Test 2: upGrade and downGrade ===" << std::endl;
	try
	{
		b1.downGrade(5);
		b2.upGrade(-1500);
		b3.upGrade(5);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test 3: upGrade too high (grade becomes < 1)
	std::cout << std::endl << "=== Test 3: upGrade too high (GradeTooHighException) ===" << std::endl;
	try
	{
		Bureaucrat b4("Alice", 2);
		std::cout << b4 << std::endl;
		b4.upGrade(5);
		std::cout << b4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test 4: downGrade too low (grade becomes > 150)
	std::cout << std::endl << "=== Test 4: downGrade too low (GradeTooLowException) ===" << std::endl;
	try
	{
		Bureaucrat b5("Bob", 149);
		std::cout << b5 << std::endl;
		b5.downGrade(5);
		std::cout << b5 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test 5: Creation with invalid grade (too high)
	std::cout << std::endl << "=== Test 5: Creation with grade 0 (GradeTooHighException) ===" << std::endl;
	try
	{
		Bureaucrat b6("Charlie", 0);
		std::cout << b6 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test 6: Creation with invalid grade (too low)
	std::cout << std::endl << "=== Test 6: Creation with grade 151 (GradeTooLowException) ===" << std::endl;
	try
	{
		Bureaucrat b7("Diana", 151);
		std::cout << b7 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}