/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:39:10 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/22 11:39:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _number;
	std::string _secret;
	int         _id;

public:
	const std::string & first_name() const;

	const std::string & last_name() const;

	const std::string & nickname() const;

	int id() const;

private:
	int _get_input(std::string &dest, const char *prompt);

public:
	int		fill_contact();
	void	show_contact();

	explicit Contact(int id);
	Contact();
};

#endif
