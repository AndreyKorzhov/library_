#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include "Reader.h"
using namespace std;

void ShowMenu(){
    cout << "\n\n\n";
    cout<< "Пункты меню : " <<endl;
    cout<< "1. Ввод данных библиотеки : " <<endl;
    cout<< "2. Вывод всей библиотеки : "<<endl;
    cout<< "3. Поиск книги : "<<endl;
    cout << endl;
    cout<<"0. Выход "<<endl;
}

void Input(map<string,Reader> &library,Reader &reader)
{
    string book;

    cout << "Enter name book : "; cin >> reader.name_book;
    cout << "Enter author book : "; cin >> reader.author;
    cout << "Enter name reader : "; cin >> reader.name;
    cout << "Enter lastname reader : "; cin >> reader.lastname;
    book = reader.name_book;
    library.insert(pair<string,Reader>(book,reader));

}
void Show_Library(map<string,Reader> library)
{
    for (auto element : library) {
        cout << "name book : " << element.second.name_book << endl;
        cout << "author book : " << element.second.author << endl;
        cout << "name reader : " << element.second.name << endl;
        cout << "lastname reader : " << element.second.lastname << endl;
        cout << endl;
    }
}
void Exp_File(map<string,Reader> &library,Reader &reader)
{
    ofstream file_library("library.csv", ios_base::app);

    if (file_library.is_open())
    {
        file_library    << reader.name_book << ";"
                        << reader.author << ";"
                        << reader.name << ";"
                        << reader.lastname;

    } else cout << "No open file!" << endl;
    file_library.close();
}

void Imp_File(map<string,Reader> &library)
{
    Reader temp;
    string book,str;
    ifstream file_library("library.csv");

    if (file_library.is_open())
    {
        while (!file_library.eof())
        {
            getline(file_library,str ,';');
            book = str;temp.name_book = str;
            getline(file_library,temp.author ,';');
            getline(file_library,temp.name ,';');
            getline(file_library,temp.lastname);
            library.insert(make_pair(book,temp));

        }


    } else cout << "No open file!" << endl;
    file_library.close();
}