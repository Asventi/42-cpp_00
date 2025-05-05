/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:39:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/22 11:39:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <string>
#include <iostream>

const std::string & Contact::first_name() const
{
	return _first_name;
}

const std::string & Contact::last_name() const
{
	return _last_name;
}

const std::string & Contact::nickname() const
{
	return _nickname;
}

int Contact::id() const
{
	return _id;
}

int	Contact::_get_input(std::string &dest, const char *prompt)
{
	while (std::cin.good())
	{
		std::cout << prompt;
		std::getline(std::cin, dest);
		if (!dest.empty())
			return (0);
		std::cout << "\t(input must not be empty)" << std::endl;
	}
	return (1);
}

int	Contact::fill_contact()
{
	int res;

	res = _get_input(_first_name, "\tFirst Name: ");
	res += _get_input(_last_name, "\tLast Name: ");
	res += _get_input(_nickname, "\tNickname: ");
	res += _get_input(_number, "\tPhone Number: ");
	res += _get_input(_secret, "\tYour \033[1mDarkest\033[0m Secret: ");
	return (res);
}

void Contact::show_contact()
{
	std::cout << "\tFirst Name: " << _first_name << std::endl;
	std::cout << "\tLast Name: " << _last_name << std::endl;
	std::cout << "\tNickame: " << _nickname << std::endl;
	std::cout << "\tNumber: " << _number << std::endl;
	std::cout << "\tDarkest Secret: " << _secret << std::endl;
}


Contact::Contact(int id): _id(id) {}

Contact::Contact(): _id(0) {}
