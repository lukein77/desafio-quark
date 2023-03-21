#include "View.h"
#include <iostream>

View::View() {
    SetConsoleTitleW(L"El Negocio de la Ropa");
	setlocale(LC_ALL, "es_Es");
    showMainMenu();
}

void View::print(const std::string &text) {
    std::cout << text << std::endl;
}

void View::showMainMenu() {
    

    char option = '0';

    do {
        std::system("cls");
        print("Esto es una prueba del menu.");
        print("Pulse X para salir u otra tecla para repetir el mensaje.");
        
        std::cin.get(option);

        if (option == 'c') {
            std::system("cls");
            print("Esto es otra prueba.");
            waitForKey();
        }
    } while ((option != 'x') || (option != 'x'));
}

void View::waitForKey() {
    print("Presione una tecla para continuar.");
    std::cin.get();
    std::cin.ignore();
}