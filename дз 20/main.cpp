//
//  main.cpp
//  дз 20
//
//  Created by Егор Джемлиханов on 05.11.2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void addSlovo(map<string, string>& dict)
{
    string slovo, perevod;
    cout << "напишите слово на английском: ";
    cin >> slovo;
    cout << "напишите перевод: ";
    cin >> perevod;
    dict[slovo] = perevod;
    cout << "слово добавлено\n";
}

void deleteSlovo(map<string, string>& dict)
{
    string slovo;
    cout << "напишите слово для удаления: ";
    cin >> slovo;
    auto it = dict.find(slovo);
    if (it != dict.end())
    {
        dict.erase(it);
        cout << "слово удалено\n";
    }
    else
    {
        cout << "слово не найдено\n";
    }
}

void saveSlovo(map<string, string>& dict)
{
    ofstream file("slovar.txt");
    if (file.is_open())
    {
        for (const auto& entry : dict)
        {
            file << entry.first << " - " << entry.second << endl;
        }
        file.close();
        cout << "словарь сохранен в файл\n";
    }
    else
    {
        cout << "ошибка при открытии файла\n";
    }
}

void searchSlovo(map<string, string>& dict)
{
    string s;
    cout << "напишите слово для поиска -> ";
    cin >> s;
    auto ptrf = dict.find(s);
    if (ptrf != dict.end())
    {
        system("cls");
        system("color 0B");
        cout << ptrf->second << endl;
    }
    else
    {
        system("cls");
        system("color 0C");
    }
}

void displaySlovar(const map<string, string>& dict)
{
    cout << "словарь:\n";
    for (const auto& entry : dict)
    {
        cout << entry.first << " - " << entry.second << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    map<string, string> dict;
    dict.insert(make_pair("dog", "собака"));
    dict.insert(make_pair("cat", "кошка"));
    dict.insert(make_pair("parrot", "попугай"));

    int vibor;
    do
    {
        cout << "\nменю:\n";
        cout << "1. добавить слово\n";
        cout << "2. удалить слово\n";
        cout << "3. найти слово\n";
        cout << "4. сохранить в файл\n";
        cout << "5. показать словарь\n";
        cout << "0. выйти\n";
        cout << "выберите действие: ";
        cin >> vibor;

        switch (vibor)
        {
        case 1:
                addSlovo(dict);
            break;
        case 2:
                deleteSlovo(dict);
            break;
        case 3:
                searchSlovo(dict);
            break;
        case 4:
                saveSlovo(dict);
            break;
        case 5:
                displaySlovar(dict);
            break;
        case 0:
            cout << "выход\n";
            break;
        default:
            cout << "ошибка\n";
        }
    }
    while (vibor != 0);

    return 0;


}
