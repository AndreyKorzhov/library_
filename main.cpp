
#include <map>
#include <string>
#include "Find.h"
#include "Reader.h"
#include "ShowInput.h"
using namespace std;


int main() {
    system("chcp 65001");

    Reader reader;
    string books;
    map<string,Reader> library;
    int choice;
    bool flagExit = false;
    do {
        ShowMenu();
        cout << endl << "Введите пункт меню:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case 1:
                Input(library,reader);
                Exp_File(library,reader);
                break;
            case 2:
                Imp_File(library);
                Show_Library(library);
                break;
            case 3:
                Imp_File(library);
                Find_Library(library,reader);
                break;

            case 0:
                flagExit=true;
                break;
            default:
                break;
        }
    }while (!flagExit);
}