/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:08:39 by lscheupl          #+#    #+#             */
/*   Updated: 2025/07/25 17:19:51 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <contact.hpp>

class PhoneBook
{
    private:
    Contact book[8];
    int lastInput;
    public:
    void setLastInput(int input);
    void addContact();
    void searchContact();
    void exitBook();
};