#include <iostream> //std::cout
#include <cctype>   //toupper
#include <string>

int main(int ac, char **av)
{
    if (ac == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++){
        std::string temp(av[i]); // std::stirng copy, stack memory
        // #include <string_view>
        // std::string_view temp(av[i])
        // no copy, just a pointer + length
        for (std::string::size_type j = 0; j < temp.size(); j++)
            temp[j] = std::toupper((unsigned char)temp[j]);
        std::cout << temp;
        if (i < ac -1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}

// code reveiew feedback
//./megaphtone "aaa " ! "bbb"
// I printed out an extra space