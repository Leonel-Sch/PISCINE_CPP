/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:43:52 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/12 00:00:19 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <unistd.h>

int main()
{
    Harl harl;
    for (int i = 0; i < 20; i++)
    {
       usleep(100000);
        harl.complain("DEBUG");
       usleep(100000);
      harl.complain("INFO");
      usleep(100000);
       harl.complain("WARNING");
      usleep(100000);
      harl.complain("ERROR");
    }
}