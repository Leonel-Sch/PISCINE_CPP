/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:50:47 by lscheupl          #+#    #+#             */
/*   Updated: 2025/09/11 23:43:01 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

int main()
{
    std :: string filename = "fichier.txt";
    std :: string s1 = "caca";
    std :: string s2 = "prout";
    std :: string origin_file;
    std :: string destination_file = "";
    std :: string temp;
    
    std :: ifstream inputFile(filename.c_str());
    std :: ofstream outputFile("sortie.txt");
    
    int i = 0;
    int j = 0;
    if (s1.empty())
        return (std :: cout << "error s1 is empty\n", 1);
    if (s2.empty())
        return (std :: cout << "error s2 is empty\n", 1);
    if (!(outputFile.is_open()))
        return (std :: cout << "error could'nt open the outfile\n", 1);
    
    if (inputFile.is_open())
    {
        while(std :: getline(inputFile, temp))
        {
            origin_file += temp + "\n";
        }
    }
    else
        return(std :: cout << "error could'nt open " << filename << std :: endl, 1);

    while ((i = origin_file.find(s1, j)) >= 0)
    {
        destination_file += origin_file.substr(j, i - j);
        destination_file += s2;
        j = i + s1.length();
    }
    
    destination_file += origin_file.substr(j, origin_file.length());
    
    std :: cout << destination_file;
    
    outputFile << destination_file;

    inputFile.close();
    outputFile.close();
    return (0);
}