#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 1. Знайти індекс i таке, що s[i] — третя за порядком кома
int FindThirdCommaIndex(const char *str)
{
    int commaCount = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
        {
            commaCount++;
            if (commaCount == 3)
                return i; // Повертаємо індекс третьої коми
        }
    }
    return -1; // Якщо третю кому не знайдено
}

// 2. Замінити кожну кому парою зірочок "**"
char *ChangeCommasToStars(char *str)
{
    size_t len = strlen(str);

    // Рахуємо кількість ком, щоб правильно виділити пам'ять
    int commaCount = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == ',')
            commaCount++;
    }

    // Кожна кома додає +1 символ (1 кома замінюється на 2 зірочки)
    char *tmp = new char[len + commaCount + 1];

    size_t i = 0;
    size_t j = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ',')
        {
            tmp[j++] = '*';
            tmp[j++] = '*';
            i++;
        }
        else
        {
            tmp[j++] = str[i++];
        }
    }
    tmp[j] = '\0';

    strcpy(str, tmp); // Скопіювати результат назад у str
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int thirdCommaIdx = FindThirdCommaIndex(str);
    if (thirdCommaIdx != -1)
        cout << "Index of 3rd comma: " << thirdCommaIdx << endl;
    else
        cout << "The string contains less than 3 commas!" << endl;

    char *dest = ChangeCommasToStars(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // Звільнення пам'яті
    return 0;
}