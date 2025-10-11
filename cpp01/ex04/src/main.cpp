/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 17:57:40 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>   //find, erase, insert, length, empty, +=
#include <iostream> //std::cout, std::endl
#include <fstream>  //filestream; openm is_open, get line
#include <sys/stat.h>   //for checking if it is regular file

bool is_regular_file(char *file)
{  
    struct stat sb;
    if (stat(file, &sb) != 0)
        return false;
    return S_ISREG(sb.st_mode);
}
 
// All the member functions of the class std::string are allowed except replace
// std::string::npos, a maxmax macros
std::string ft_replace(std::string content, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
        return content;
    size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	return content;
}

int main(int ac, char **av)
{
    //input check
    if (ac != 4)
    {
        std::cout << "Error: wrong av number." << std::endl;
        return 1;
    }
    //check if it is a regular file
    if (!is_regular_file(av[1]))
    {
        std::cout << "Error: file is not a regular file." << std::endl;
        return 1;
    }
    //open av[1],
    std::ifstream ifs(av[1]);
    if (!ifs.is_open())
    {
        std::cout << "Error: openning infile failed." << std::endl;
        return 1;
    }
    //copy av[1] content // and check content is null or not
    std::string content;
    char c;
    while (ifs.get(c))
        content += c;
    ifs.close();
    //create ac[1].replace //paste av[1] content to ac[1].replace
    std::string out_filename = std::string(av[1]) + ".replace";
    std::ofstream ofs(out_filename.c_str());
    if (!ofs.is_open())
    {
        std::cout << "Error: openning outfile failed." << std::endl;
        return 1;
    }
    ofs << ft_replace(content, av[2], av[3]);
    ofs.close();
    return 0;
}
