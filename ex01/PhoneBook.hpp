/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:21:20 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/15 15:21:20 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int     _size;
    int     _id;
public:
    void    add_contact(Contact &contact);
    void    show_contacts();
    void    search_contacts();
    PhoneBook();
    ~PhoneBook();
    PhoneBook(const PhoneBook&);
    PhoneBook& operator=(const PhoneBook& e);
};

#endif
