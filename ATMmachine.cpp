#include <iostream>
#include <ctime>
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
bool foolproofTelephoneNumber(long a)
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
int GetRandomNumber(int min, int max)
{
    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число - формула
    int num = min + rand() % (max - min + 1);

    return num;
}
bool FileInPin(int a)
{
    
        int pin;
        std::ifstream finPin;
        finPin.open("pin-codes.txt", std::ios_base::in);
        if (!finPin.is_open())
            return 0;
        finPin >> pin;
        if (pin == a)
        {
            return true;
        }
        else
        {
            
            return false;
        }
        
    
}
bool fileOutput(int a, int b)
{
    if (a == 1 && b == 1)
    {
        std::ofstream foutUserId;
        foutUserId.open("users_id.txt", std::ofstream::app);
        if (!foutUserId.is_open())
        {
            std::cout << "Ошибка открытия файла!";
            return 0;
        }
        foutUserId << " - " << b << '\n';
    }
    if (a == 1 && b == 0)
    {
        std::ofstream foutUserId;
        foutUserId.open("users_id.txt", std::ofstream::app);
        if (!foutUserId.is_open())
        {
            std::cout << "Ошибка открытия файла!";
            return 0;
        }
        foutUserId << " - " << b << '\n';
    }
    if (a == 2)
    {
        std::ofstream foutPin;
        foutPin.open("pin-codes.txt");
        if (!foutPin.is_open())
        {
            std::cout << "Ошибка открытия файла!";
            return 0;
        }
        foutPin << b;
        foutPin.close();
        return 1;
    }
  
}
int fileInput(int a, int b)
{
    if (a == 1)
    {
        int money;
        std::ifstream finBalance;
        std::ofstream foutBalance;
        finBalance.open("balances.txt");
        if (!finBalance.is_open())
            return 0;
        finBalance >> money;
        finBalance.close();
        money -= b;
        if (money < 0)
            return 1;
        if (money >= 0)
        {
            foutBalance.open("balances.txt");
            foutBalance << money;
            foutBalance.close();
            return money;
        }
    }
    if (a == 2)
    {
        int money;
        std::ifstream finBalance;
        std::ofstream foutBalance;
        finBalance.open("balances.txt");

        if (!finBalance.is_open())
            return 0;

        finBalance >> money;
        finBalance.close();
        money += b;

        foutBalance.open("balances.txt");
        foutBalance << money;
        foutBalance.close();
        return 1;
    }
}
bool fileOutputLogs(int a, int b)
{
    std::ofstream foutLogs;
    foutLogs.open("logs.txt", std::ofstream::app);
    if (!foutLogs.is_open())
        return false;

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);


    if (a == 1)
    {
        foutLogs << "Пользователь снял деньги: " << b << " " << asctime(timeinfo) << "\n";
        std::cin.get();
        foutLogs.close();
    }
    if (a == 2)
    {
        foutLogs << "Пользователь положил деньги на телефон: " << b << " " << asctime(timeinfo) << "\n";
        std::cin.get();
        foutLogs.close();
    }
    if (a == 3)
    {
        foutLogs << "Пользователь пополнил счет на: " << b << " " << asctime(timeinfo) << "\n";
        std::cin.get();
        foutLogs.close();
    }
    if (a == 4)
    {
        foutLogs << "Пользователь заблокировал карту. " << asctime(timeinfo) << "\n";
        std::cin.get();
        foutLogs.close();
    }
    if (a == 0)
    {
        foutLogs << "Пользователь посмотрел баланс: " << b << " " << asctime(timeinfo) << "\n";
        std::cin.get();
        foutLogs.close();
    }
    return true;
}
int main()
{
    setlocale(LC_ALL, "ru");
    int userBalance = 1000, userPin, userChoise, payTelephoneNumber;
    const int arrLength = 6;
    int userID[arrLength];
    
    do
    {
        std::cout << "Добро пожаловать в банкомат!\n"
        "1 - создать карту.\n2 - выйти из программы.\n";
        
        std::cin >> userChoise;
        if (foolproof(userChoise == true))
        {
            if (userChoise == 1)
            {
                std::cout << "Ваш id: ";
                for (int i = 0; i < arrLength; i++)
                {
                    userID[i] = GetRandomNumber(0, 10);
                    std::cout << userID[i];
                }
                std::cout << std::endl;

                std::ofstream foutUserId;
                foutUserId.open("users_id.txt", std::ofstream::app);
                if (!foutUserId.is_open())
                {
                    std::cout << "Ошибка открытия файла!";
                    return 0;
                }
                {
                    for (int i = 0; i < arrLength; i++)
                    {
                        foutUserId << userID[i];
                    }
                    foutUserId.close();
                }
                fileOutput(1, 1);
                std::cout << "Вы успешно зарегистрировали свою карту!\n"
                    "Придумайте пин код(4 цифры не начиная с нуля): ";

                breakAll:
                std::cin >> userPin;
                if (foolproof(userPin) == true && userPin > 999 && userPin < 10000)
                {
                    fileOutput(2, userPin);
                    std::cout << "Вы успешно зарегистрировали свою карту!\n"
                        "Осталось только войти)))\n";
                }
                else
                {
                    goto breakAll;
                }
                int count = 0;
                std::cout << "Введите ваш pin: ";

                do
                {                 
                    std::cin >> userPin;
                    if(foolproof(userPin) == true)
                    {
                        if (FileInPin(userPin) == false)
                        {
                            count++;
                            if (count == 3)
                            {
                                std::cout << "Увы, не угадали(";
                                std::ofstream foutUserId;
                                foutUserId.open("users_id.txt", std::ofstream::app);
                                if (!foutUserId.is_open())
                                {
                                    std::cout << "Ошибка открытия файла!";
                                    return 0;
                                }
                                {
                                    for (int i = 0; i < arrLength; i++)
                                    {
                                        foutUserId << userID[i];
                                    }
                                    foutUserId.close();
                                }
                                fileOutput(1, 0);

                                return 0;
                            }

                            std::cout << "Не првильный пин код.\n"
                                "У вас осталось " << 3 - count << " Попыток.\n";
                            std::cout << "Введите пин код: ";
                        }
                        else
                            break;
                        
                    }
                } while (count != 3 || foolproof(userPin) == false);

                std::cout << "Вы успешно вошли в систему!\n";
                    
                do
                {
                    breakAl:
                    std::cout << "Какую операцию хотите совершить? (1, 2, 3)\n"
                        "1 - Снять деньги.\n"
                        "2 - Оплатить мобильную связь.\n"
                        "3 - Пополнить счет.\n"
                        "4 - Заблокировать карту.\n"
                        "0 - Посмотреть баланс.\n";
                    int withdrawalAmount;

                    std::cin >> userChoise;
                    if (foolproof(userChoise) == true || userChoise >= 1 || userChoise <= 4)
                    {
                        if (userChoise == 1)
                        {
                        breakAll3:
                            std::cout << "Введите сумму для снятия: ";
                            std::cin >> withdrawalAmount;
                            if (foolproof(withdrawalAmount) == true)
                            {
                                if (fileInput(1, withdrawalAmount) == 1)
                                {
                                    std::cout << "Недостаточно средств!\n"
                                        "Попробуйте еще раз:\n ";
                                    goto breakAll3;

                                }
                                else
                                {
                                    std::cout << "Вы успешно обналичили " << withdrawalAmount << " рублей.\n";
                                    fileOutputLogs(1, withdrawalAmount);
                                }
                            }
                        }
                        if (userChoise == 2)
                        {
                            long long telephoneNumber;
                            int payTelephoneNumber;
                            std::cout << "Введите номер телефона: ";
                            std::cin >> telephoneNumber;
                            if (foolproofTelephoneNumber(telephoneNumber) == true)
                            {
                                std::cout << "Введите сумму для оплаты мобильной связи: ";
                                std::cin >> payTelephoneNumber;
                                if (foolproof(payTelephoneNumber) == true)
                                {
                                    if (fileInput(1, payTelephoneNumber) == 1)
                                    {
                                        std::cout << "Недостаточно средств!\nПопробуйте еще раз:\n ";
                                        goto breakAl;
                                    }
                                    else
                                    {
                                        std::cout << "Вы успешно оплатили мобильную связь!\n";
                                        fileOutputLogs(2, payTelephoneNumber);
                                    }
                                }
                            }
                        }
                        if (userChoise == 3)
                        {
                            int topUpAccount;
                            std::cout << "Введите сумму для пополнения: ";
                            std::cin >> topUpAccount;
                            if (foolproof(topUpAccount) == true)
                            {
                                if (fileInput(2, topUpAccount) == 1)
                                {
                                    std::cout << "Вы успешно пополнили счет!\n";
                                    fileOutputLogs(3, topUpAccount);
                                }
                            }
                        }
                        if (userChoise == 4)
                        {
                            std::ofstream foutUserId;
                            foutUserId.open("users_id.txt", std::ofstream::app);
                            if (!foutUserId.is_open())
                            {
                                std::cout << "Ошибка открытия файла!";
                                return 0;
                            }
                            {
                                for (int i = 0; i < arrLength; i++)
                                {
                                    foutUserId << userID[i];
                                }
                                foutUserId.close();
                                fileOutputLogs(4, 0);
                            }
                            fileOutput(1, 0);
                            std::cout << "Вы успешно заблокировали карту!";
                        }
                        if (userChoise == 0)
                        {
                            std::ifstream finStorage;
                            finStorage.open("balances.txt");
                            if (!finStorage.is_open())
                            {
                                std::cout << "Ошибка открытия файла!";
                                return 0;
                            }
                            finStorage >> userBalance;
                            std::cout << "Ваш баланс: " << userBalance << '\n';
                            fileOutputLogs(0, userBalance);
                        }      
                    }
                } while (userChoise == 1 || userChoise == 2 || userChoise == 3 || userChoise == 0);
            }
        }
    } while (foolproof(userChoise) != true);
}


