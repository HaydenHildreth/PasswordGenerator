#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

std::vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

std::vector<char> alphabetWithCaps = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y',
'z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

std::vector<char> numWithSpecial = {'0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','^','&','*','(',')'};

int main()
{
    srand(time(NULL));

    std::string password;
    int lenPw, lenChar, temp = 0;
    std::cout << "Enter the length you would like your password to be: "; std::cin >> lenPw;
    std::cout << "Enter the amount of letters you would like your password to be: "; std::cin >> lenChar;

    if(lenPw > lenChar)
    {
        int flag = 0;
        int lenNum = lenPw - lenChar;
        
        std::cout << "Would you like to use capitol letters as well (1=yes/2=no): "; std::cin >> flag;

        switch (flag)
        {
        case 1:
            for(int i = 0; i < lenChar; i++)
            {
                temp = rand() % 52; 
                password = password + alphabetWithCaps[temp];
            }
            for(int j = 0; j < lenNum; j++)
            {
                temp = rand() % 20;
                password = password + numWithSpecial[temp];
            }
            break;
        case 2:
            for(int i = 0; i < lenChar; i++)
            {
                temp = rand() % 26; 
                password = password + alphabetWithCaps[temp];
            }
            for(int j = 0; j < lenNum; j++)
            {
                temp = rand() % 20;
                password = password + numWithSpecial[temp];
            }
            break;
        default:
            std::cout << "An error occured, input must be either 1 or 2...";
            break;
        }
    }
    else
    {
        std::cout << "Error... amount of letters must be less than length of password;";
    }
    
    std::cout << "Your randomly generated password is: " << password << "\n";

    return 0;
}
