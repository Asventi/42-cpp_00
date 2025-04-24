/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:51:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/17 11:51:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

void	get_input(std::string &dest, const char *prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, dest);
		if (!dest.empty())
			break ;
		std::cout << "\t(input must not be empty)" << std::endl;
	}
}

void	fill_contact(Contact &contact)
{
	get_input(contact.first_name, "\tFirst Name: ");
	get_input(contact.last_name, "\tLast Name: ");
	get_input(contact.nickname, "\tNickname: ");
	get_input(contact.number, "\tPhone Number: ");
	get_input(contact.secret, "\tYour \033[1mDarkest\033[0m Secret: ");
}

int	main(int c, char **args)
{
	std::string	cmd;
	PhoneBook	*phone_book;
	Contact		contact;

	(void)c;
	(void)args;
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
		{
			fill_contact(contact);
			phone_book->add_contact(contact);
			std::cout << "\nContact has been added succesfully." << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			phone_book->search_contacts();
		}
		else if (cmd == "EXIT")
			return (0);
	}
}
