#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Функція обчислення довжини найдовшого слова у рядку
size_t MaxLength(const string &s)
{
    size_t maxLen = 0;
    size_t start = 0;
    size_t finish;

    // Рядок усіх можливих роздільників (пробіли та знаки пунктуації)
    const string delimiters = " \t\n\r,.:;!?-()\"'[]{}<>/\\";

    // Пошук початку першого слова (перший символ, що НЕ є роздільником)
    start = s.find_first_not_of(delimiters, 0);

    while (start != string::npos)
    {
        // Пошук кінця слова (перший роздільник після початку слова)
        finish = s.find_first_of(delimiters, start);

        if (finish == string::npos)
            finish = s.length();

        size_t currentLen = finish - start;

        // Оновлюємо максимальну довжину
        if (currentLen > maxLen)
            maxLen = currentLen;

        // Переходимо до пошуку наступного слова
        start = s.find_first_not_of(delimiters, finish);
    }

    return maxLen;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "Length of the longest word: " << MaxLength(str) << endl;

    return 0;
}