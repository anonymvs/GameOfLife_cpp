#include <iostream>
#include "header.h"
#include "field.h"

using namespace std;

void mainMenu() {
    main_menu menu;
    string x;
    Field baseField;
    menu_text('0');
    while(getline(cin, x) && x[0] != '5') {
        if (x[0] > '5' || x[0] < '0' || x.length() != 1) {
            cout << "Non existing sub menu: " << x << endl;
        } else {
            menu = main_menu(x[0]);
            switch(menu) {
            case(area):
                baseField = areaf();
                menu_text('1');
                break;
            case(base):
                basef(baseField);
                break;
            case(load):
                loadf();
                break;
            case(start):
                //startf();
                break;
            case(quit):
                //quitf();
                break;
            }
        }
    }
}

void menu_text(char c) {
    main_menu state = main_menu(c);
    switch (state) {
      case(full):
        cout << "--- MENU ---" << endl;
        cout << ":: Kerem irja be az on altal valasztott menupont szamat ::" << endl;
        cout << "1 - Jatekter meretenek megadasa" << endl;
        cout << "2 - Kezdo koordinatak leosztasa" << endl;
        cout << "3 - Szimulacio betoltese fajlbol" << endl;
        cout << "4 - Szimulacio inditasa" << endl;
        cout << "5 - Kilepes" << endl;
        break;
      case (area):
        cout << "--- MENU ---" << endl;
        cout << ":: Kerem irja be az on altal valasztott menupont szamat ::" << endl;
        cout << "2 - Kezdo koordinatak leosztasa" << endl;
        cout << "4 - Szimulacio inditasa" << endl;
        cout << "5 - Kilepes" << endl;
        break;
      case (base):
        cout << "--- MENU ---" << endl;
        cout << ":: Kerem irja be az on altal valasztott menupont szamat ::" << endl;
        cout << "4 - Szimulacio inditasa" << endl;
        cout << "5 - Kilepes" << endl;
        break;
      case (load):
        cout << "--- MENU ---" << endl;
        cout << ":: Kerem irja be az on altal valasztott menupont szamat ::" << endl;
        cout << "4 - Szimulacio inditasa" << endl;
        cout << "5 - Kilepes" << endl;
        break;
      case (start):
        break;
      case (quit):
        break;
    }
}
