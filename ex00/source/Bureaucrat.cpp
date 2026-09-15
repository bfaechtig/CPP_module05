/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaechti <benjamin.faechtig@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:40:26 by bfaechti          #+#    #+#             */
/*   Updated: 2026/03/12 15:13:04 by bfaechti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/* ===== Constructor ===== */
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat Constructor Called" << std::endl;
}

/* ===== Copy Constructor ===== */
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

/* ===== Operator Overload ===== */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		_grade = other._grade;
	std::cout << "Bureaucrat Overload Operator Called" << std::endl;
	return (*this);
}

/* ===== Destructor ===== */
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

/* ===== Functions  ===== */
std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::upGrade(unsigned int i) {
	if (_grade - i < 1 || _grade + i > 150)
		throw GradeTooHighException();
	_grade -= i;
}

void Bureaucrat::downGrade(unsigned int i) {
	if (_grade + i > 150 || _grade -i < 1)
		throw GradeTooLowException();
	_grade += i;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade to high to be assigned.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade to low to be assigned.");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return os;
}