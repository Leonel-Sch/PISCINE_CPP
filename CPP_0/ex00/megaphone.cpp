/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:56:06 by lscheupl          #+#    #+#             */
/*   Updated: 2025/04/04 16:15:37 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

char *str_upper(char *str)
{
    for(int i = 0;str[i] != '\0'; i++)
    {
        if (str[i] > 97 && str[i] < 122)
            str[i] -= 32;
    }
    return str;
}

int main(int argc, char **argv)
{
    for (int i = 1; argv[i] !=NULL; i++)
    {
        str_upper(argv[i]);
        std :: cout << argv[i];
    }
    if (argc == 1)
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
    else 
        std :: cout << std :: endl;
    return 0;
}