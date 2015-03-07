#include <iostream>
#include "header.h"

using namespace std;

void mainMenu() {
    main_menu menu;
    string x;
    cout << "--- MENU ---" << endl;
    cout << ":: Kerem irja be az on altal valasztott menupont szamat::" << endl;
    cout << "1 - Jatekter meretenek megadasa" << endl;
    cout << "2 - Kezdo koordinatak leosztasa" << endl;
    cout << "3 - Szimulacio betoltese fajlbol" << endl;
    cout << "4 - Szimulacio inditasa" << endl;
    cout << "5 - Kilepes" << endl;
    while(getline(cin, x) && x[0] != '5') {
        if (x[0] > '5' || x[0] < '0' || x.length() != 1) {
            cout << "Non existing sub menu: " << x << endl;
        } else {
            menu = main_menu(x[0]);
            switch(menu) {
            case(area):
                cout << "a nullat irtam be";
                areaf();
                break;
            case(base):
                basef();
                break;
            case(load):
                loadf();
                break;
            case(start):
                startf();
                break;
            case(quit):
                quitf();
                break;
            }
        }
    }
}
