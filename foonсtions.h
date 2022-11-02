#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
void logs(int numberOfFunction, int userOperation)
{
	int userID;
	std::ifstream finID;
	std::ofstream foutLogs;
	finID.open("ID.txt");
	finID >> userID;
	finID.close();
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	foutLogs.open("logs.txt", std::ofstream::app);
	if (!foutLogs.is_open())
		return;
	if (numberOfFunction == 1)
	{
		foutLogs << userID << " Посмотрел баланс: " << userOperation << " " << asctime(timeinfo) << "\n";
		std::cin.get();
		foutLogs.close();
	}
	if (numberOfFunction == 2)
	{
		foutLogs << userID << " Пополнил счет на: " << userOperation << " " << asctime(timeinfo) << "\n";
		std::cin.get();
		foutLogs.close();
	}
	if (numberOfFunction == 3)
	{
		foutLogs << userID << " Снял деньги: " << userOperation << " " << asctime(timeinfo) << "\n";
		std::cin.get();
		foutLogs.close();
	}
	if (numberOfFunction == 4)
	{
		foutLogs << userID << " Оплатил мобильную связь: " << userOperation << " " << asctime(timeinfo) << "\n";
		std::cin.get();
		foutLogs.close();
	}
	if (numberOfFunction == 5)
	{
		foutLogs << userID << " заблокировал карту. " << " " << asctime(timeinfo) << "\n";
		std::cin.get();
		foutLogs.close();
	}
}
void userBalance()
{
	std::ifstream finBalance;
	int balance;
	finBalance.open("balances.txt");
	if (!finBalance.is_open())
		return;
	finBalance >> balance;
	finBalance.close();
	std::cout << "You balance: " << balance << '\n';
	logs(1, balance);
}
void topUpTheAccount(int userMoney)
{
	int balance;
	std::ifstream finBalance;
	std::ofstream foutBalance;
	finBalance.open("balances.txt");
	if (!finBalance.is_open())
		return;
	finBalance >> balance;
	finBalance.close();
	balance += userMoney;
	foutBalance.open("balances.txt");
	if (!foutBalance.is_open())
		return;
	foutBalance << balance;
	foutBalance.close();
	std::cout << "You have successfully topped up your account!\n";
	logs(2, userMoney);
}
bool WithdrawMoney(int userMoney)
{
	int balance;
	std::ifstream finBalance;
	std::ofstream foutBalance;
	finBalance.open("balances.txt");
	finBalance >> balance;
	finBalance.close();
	balance -= userMoney;
	if (balance < 0)
	{
		std::cout << "Insufficient funds!\n";
		return false;
	}
	if (balance >= 0)
	{
		std::cout << "You have successfully cashed out " << userMoney << '\n';
		foutBalance.open("balances.txt");
		foutBalance << balance;
		foutBalance.close();
		logs(3, userMoney);
		return true;
	}
}
bool payBuyPhone(int userMoney)
{
	int balance;
	std::ifstream finBalance;
	std::ofstream foutBalance;
	finBalance.open("balances.txt");
	finBalance >> balance;
	finBalance.close();
	balance -= userMoney;
	if (balance < 0)
	{
		std::cout << "Insufficient funds!\n";
		return false;
	}
	if (balance >= 0)
	{
		std::cout << "You have successfully paid for the phone " << userMoney << '\n';
		foutBalance.open("balances.txt");
		foutBalance << balance;
		foutBalance.close();
		logs(4, userMoney);
		return true;
	}
}
void blockTheCard()
{
	int userID;
	std::ifstream finID;
	std::ofstream foutID;
	finID.open("ID.txt", std::ios_base::in);
	finID >> userID;
	finID.close();
	foutID.open("ID.txt", std::ofstream::app);
	foutID << userID << " - " << 0 << '\n';
	foutID.close();
	std::cout << "You have successfully blocked the card!\n";
	return;
}
void userChoise(int a)
{
	
	
	if (a == 1)
	{
		userBalance();
	}
	if (a == 2)
	{
		int replenishment;
		std::cout << "Enter the amount: ";
		std::cin >> replenishment;
		if (foolproof(replenishment) == true)
			topUpTheAccount(replenishment);
	}
	if (a == 3)
	{
		int money;
		do
		{
			std::cout << "Enter the amount: ";
			std::cin >> money;
		} while (WithdrawMoney(money) != true);
	}
	if (a == 4)
	{
		std::string telephoneNumber;
		std::cout << "Enter your phone number: ";
		std::cin >> telephoneNumber;
		int money;
		do
		{
			std::cout << "Enter the amount: ";
			std::cin >> money;
		} while (payBuyPhone(money) != true);
	}
	if (a == 5)
	{
		blockTheCard();
	}	
}

