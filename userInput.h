#include <iostream>
#include <fstream>

bool foolproof(int a)
{
	while (!a)
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		return false;
	}
	return true;
}
void fileOutPin()
{
	std::ofstream foutPin;
	foutPin.open("pin-codes.txt");
	if (!foutPin.is_open())
		return;
	foutPin << 3609;
	foutPin.close();
}
void fileOutBalance()
{
	std::ofstream foutBalance;
	foutBalance.open("balances.txt");
	if (!foutBalance.is_open())
		return;
	foutBalance << 1000;
	foutBalance.close();
}
void fileOutUserID()
{
	std::ofstream foutID;
	foutID.open("ID.txt", std::ofstream::app);
	if (!foutID.is_open())
		return;
	foutID << 1122 << " - " << 1 << '\n';
	foutID.close();
}
bool pinCodeVerification()
{
	int count = 0;
	int userPin;
	int pinCodeFromTheFile;
	std::ifstream finPinCode;
	finPinCode.open("pin-codes.txt");
	if (!finPinCode.is_open())
		return false;
	finPinCode >> pinCodeFromTheFile;
	std::cout << "Welcome to the ATM!\nEnter the PIN code :";
	do
	{
		std::cin >> userPin;
		if(foolproof(userPin) == true)
			if (userPin != pinCodeFromTheFile)
			{
				count++;
				if (count == 3)
					break;
				std::cout << "Incorrect PIN code!\nYou have " << 3 - count << " attempts left: ";
			}
			if (userPin == pinCodeFromTheFile)
				return true;
	} while (foolproof(userPin) == false || userPin < 1000 || userPin > 9999 || count != 3 || userPin != pinCodeFromTheFile);
	
}