#include <iostream>
#include "Utility.h"
#include "Fraction.h"
#include <iomanip>

int main()
{
    std::setlocale(LC_ALL, "RU");

	Calculator Calculator3000;
    Fraction temp;
    char continueOp = 'y';
    int temp_op = 0; 
    int op = 0;

    while (continueOp == 'y' || continueOp == 'Y')
    {
        std::cout << "1 - Ввести числа\n2 - Сложение\n3 - Вычитание\n4 - Умножение\n5 - Деление\n6 - Вывести дробь\n";
        std::cin >> op;
        switch (op)
        {
        case(1):
            std::cout << "Введите 1/2 если хотите ввести (1 или 2 дробь)\n";
            std::cin >> temp_op;
            if(temp_op == 1)
            {
                std::cout << "\nВведите число" << std::endl;
                std::cin >> temp;
                Calculator3000.setCalcul(temp);
                temp_op = 0;
            }
            else if(temp_op == 2)
            {
                std::cout << "\nВведите число" << std::endl;
                std::cin >> temp;
                Calculator3000.setOther(temp);
                temp_op = 0;
            }
            break;
        case(2):
            temp = Calculator3000.Addition();
            std::cout << "\nРезультат: \n";
            temp.PrintFrac();
            break;
        case(3):
            temp = Calculator3000.Substract();
            std::cout << "\nРезультат: \n";
            temp.PrintFrac();
            break;
        case(4):
            temp = Calculator3000.Multiply();
            std::cout << "\nРезультат: \n";
            temp.PrintFrac();
            break;
        case(5):
            temp = Calculator3000.Division();
            std::cout << "\nРезультат: \n";
            temp.PrintFrac();
            break;
        case(6):
            std::cout << "Введите 1/2 если хотите вывести (1 или 2 дробь)\n";
            std::cin >> temp_op;
            if (temp_op == 1)
            {
                Calculator3000.getCalcul().PrintFrac();
                temp_op = 0;
            }
            else if (temp_op == 2)
            {
                Calculator3000.getOther().PrintFrac();
                temp_op = 0;
            }
            break;
        default:
            std::cout << "\nТакой операции не существует\n";
            break;
        }

        std::cout << "\nЧтобы продолжить введите y/Y ,иначе n/N\n";
        std::cin >> continueOp;
        system("cls");
    }
    return 0;

}

