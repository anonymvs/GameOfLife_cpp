#include <iostream>
#include "header.h"
#include "field.h"

using namespace std;

void mainMenu() {
    main_menu menu;
    string x;
    int szam;
    Field baseField;
    bool loop = true;
    menu_text('0');
    getline(cin, x);
    while(x[0] != '5') {
        if (x[0] > '5' || x[0] < '0' || x.length() != 1) {
            cout << "Non existing sub menu: " << x << endl;
            getline(cin, x);
        } else {
            menu = main_menu(x[0]);
            switch(menu) {
            case(area):
                //valamiért csak 71*71 lehet...
                //szélesség nem lehet 72. a magasságnál ez nem porbléma
                baseField = areaf();
                menu_text('1');
                getline(cin, x);
                while(loop) {
                    if (x[0] > '5' || x[0] < '0' || x.length() != 1 || x[0] == '1' || x[0] == '3' ) {
                        cout << "Non existing sub menu: " << x << endl;
                        getline(cin, x);
                    } else { loop = false; }
                }
                break;
            case(base):
                basef(baseField);
                menu_text('2');
                getline(cin, x);
                break;
            case(load):
                loadf();
                getline(cin, x);
                break;
            case(start):
                cout << endl << "Hany kor fusson le a szimulaciobol? (kb 100 es 10 000 kozott erdemes hatart valasztani)" << endl;
                szam = beolv();
                cout << baseField;
                startf(baseField, szam);
                cout << endl << "--- LEFUTOTT A SZIMULACIO ---" << endl;
                getline(cin, x);
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
        cout << endl << "--- MENU ---" << endl;
        cout << ":: Kerem irja be az on altal valasztott menupont szamat ::" << endl;
        cout << "1 - Jatekter meretenek megadasa" << endl;
        cout << "2 - Kezdo koordinatak leosztasa" << endl;
        cout << "3 - Szimulacio betoltese fajlbol" << endl;
        cout << "4 - Szimulacio inditasa" << endl;
        cout << "5 - Kilepes" << endl;
        break;
      case (area):
        cout << endl << "--- MENU ---" << endl;
        cout << ":: Kerem irja be az on altal valasztott menupont szamat ::" << endl;
        cout << "2 - Kezdo koordinatak leosztasa" << endl;
        cout << "4 - Szimulacio inditasa" << endl;
        cout << "5 - Kilepes" << endl;
        break;
      case (base):
        cout << endl << "--- MENU ---" << endl;
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
        cout << endl << "--- MENU ---" << endl;
        cout << ":: Kerem irja be az on altal valasztott menupont szamat ::" << endl;
        cout << "1 - Jatekter meretenek megadasa" << endl;
        cout << "2 - Kezdo koordinatak leosztasa" << endl;
        cout << "3 - Szimulacio betoltese fajlbol" << endl;
        cout << "4 - Szimulacio inditasa" << endl;
        cout << "5 - Kilepes" << endl;
        break;
      case (quit):
        break;
    }
}
