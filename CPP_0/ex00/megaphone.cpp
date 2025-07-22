/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:56:06 by lscheupl          #+#    #+#             */
/*   Updated: 2025/04/14 16:55:16 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    for (int i = 1; argv[i] !=NULL; i++)
    {
        for(int j = 0; argv[i][j] != '\0'; j++)
            std :: cout << (char)(toupper(argv[i][j]));
    }
    if (argc == 1)
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
    else 
        std :: cout << std :: endl;
    return 0;
}
