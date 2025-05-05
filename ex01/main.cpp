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

int	main(int c, char **args)
{
	std::string	cmd;
	PhoneBook	phone_book;

	(void)c;
	(void)args;
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
		{
			if (phone_book.add_contact() != 0)
				return (1);
			std::cout << "\nContact has been added succesfully." << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			phone_book.search_contacts();
		}
		else if (cmd == "EXIT")
			return (0);
	}
	return (0);
}
