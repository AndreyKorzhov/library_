#pragma once

#include <map>
#include <iostream>
#include <string>
#include "Reader.h"

void Find_Library(map<string,Reader> library,Reader &reader)
{
string book;
cout << "Enter find book : " << endl;
cin >> book;

    auto it = library.find(book);
    if (it != library.end()) {
        reader = it->second;
        cout << "name book : " <<  reader.name_book << endl;
        cout << "author book : " << reader.author << endl;
        cout << "name reader : " << reader.name << endl;
        cout << "lastname reader : " << reader.lastname << endl;
        cout << endl;
    } else {
        cout << "No book" << endl;
    }
}