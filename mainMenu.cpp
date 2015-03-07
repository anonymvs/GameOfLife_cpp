#include <iostream>
#include "header.h"

using namespace std;

void mainMenu() {
    main_menu menu;
    int x;
    while(cin >> x) {
        menu = main_menu(x);
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
