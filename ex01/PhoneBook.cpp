/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:21:20 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/15 15:21:20 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#include "PhoneBook.hpp"

std::string	max_modifier(const std::string	&str)
{
	std::string	new_str;

	new_str = str.substr(0, 10);
	if (str.length() > 10)
		new_str[new_str.size() - 1] = '.';
	return (new_str);
}

int	PhoneBook::add_contact()
{
	Contact contact(_id);

	if (contact.fill_contact() != 0)
		return (1);
	for (int i = _size; i > 0; i--)
	{
		if (i == 8)
			_size--;
		else
			_contacts[i] = _contacts[i - 1];
	}
	_contacts[0] = contact;
	_size++;
	_id++;
	return (0);
}

void	PhoneBook::show_contacts()
{
	std::cout << "\t/-------------------------------------------\\" << std::endl;
	std::cout << "\t|        Id|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "\t|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < _size; i++)
	{
		std::cout << "\t|" << std::setw(10) << _contacts[i].id();
		std::cout << "|" << std::setw(10) << max_modifier(_contacts[i].first_name());
		std::cout << "|" << std::setw(10) << max_modifier(_contacts[i].last_name());
		std::cout << "|" << std::setw(10) << max_modifier(_contacts[i].nickname()) << "|" << std::endl;
	}
	std::cout << "\t\\-------------------------------------------/" << std::endl;
}

void	PhoneBook::search_contacts()
{
	int	id;

	show_contacts();
	std::cout << "Enter a contact id: ";
	std::cin >> id;
	if (std::cin.fail())
	{
		std::cout << "Invalid data." << std::endl;
		std::cin.clear(std::ios_base::goodbit);
		return ;
	}
	for (int i = 0; i < _size; i++)
	{
		if (_contacts[i].id() == id)
		{
			_contacts[i].show_contact();
			return ;
		}
	}
	std::cout << "Contact not found." << std::endl;
}

PhoneBook::PhoneBook()
{
	_size = 0;
	_id = 1;
}

PhoneBook::~PhoneBook() {};

PhoneBook::PhoneBook(const PhoneBook &cpy)
{
	_size = cpy._size;
	_id = cpy._id;
	for (int i = 0; i < _size; i++)
		_contacts[i] = cpy._contacts[i];
}
PhoneBook &PhoneBook::operator=(const PhoneBook &e)
{
	if (this != &e)
	{
		for (int i = 0; i < _size; i++)
			_contacts[i] = e._contacts[i];
		_size = e._size;
		_id = e._id;
	}
	return (*this);
}
