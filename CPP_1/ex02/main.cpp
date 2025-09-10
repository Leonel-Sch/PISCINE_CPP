/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:56:39 by leonel            #+#    #+#             */
/*   Updated: 2025/09/10 21:04:06 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std :: string str = "HI THIS IS BRAIN";
	std :: string &stringREF = str;
	std :: string *stringPTR = &str;
	
	std :: cout << &str << std :: endl;
	std :: cout << stringPTR << std :: endl;
	std :: cout << &stringREF << std :: endl;
	
	std :: cout << str << std :: endl;
	std :: cout << *stringPTR << std :: endl;
	std :: cout << stringREF << std :: endl;
}