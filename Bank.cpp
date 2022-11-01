#include <iostream>
#include "userInput.h"
#include "funсtions.h"


int main()
{
    fileOutPin();
    fileOutBalance();
    fileOutUserID();
    if (pinCodeVerification() == true)
    {
        std::cout << "You have successfully logged in!\n";
        int userInput;
        do
        { 
            std::cout << "1 - View the balance.\n"
            "2 - Top up your account.\n"
            "3 - Withdraw money.\n"
            "4 - Pay by phone.\n"
            "5 - Block the card.\n";
            std::cin >> userInput;
            if (foolproof(userInput) == true)
                userChoise(userInput);
            else
                std::cout << "Enter a number.\n";
        } while (foolproof(userInput) == false || userInput > 0 && userInput < 5);
    }

    return 0;
}

