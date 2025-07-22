/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:08:15 by lscheupl          #+#    #+#             */
/*   Updated: 2025/07/22 14:21:55 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
    private:
    std::string FirstName;
    std::string LastName;
    public:
    void SetName(std::string Name, int type);
    std::string getFullName() const;
};

