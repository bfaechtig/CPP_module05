/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:40:33 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/12 15:08:04 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int	_grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void upGrade(unsigned int i);
	void downGrade(unsigned int i);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);

#endif