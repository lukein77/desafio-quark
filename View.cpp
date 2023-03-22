#include "View.h"
#include "Presenter.h"
#include <iostream>
#include <windows.h>

View::View() {
    _presenter = new Presenter(this);
    SetConsoleTitleW(L"Casa de Ropa");
	setlocale(LC_ALL, "es_Es");
    showMainMenu();
}

void View::print(const std::string &text) {
    std::cout << text << std::endl;
}

void View::showHeader() {
    print("COTIZADOR EXPRESS - MENU PRINCIPAL");
    print("----------------------------------");
    print(_presenter->getStoreName() + " | " + _presenter->getStoreAddress());
    print("----------------------------------");
}

void View::showMainMenu() {

    char option = '0';


    do {
        std::system("cls");
        showHeader();
        print("Esto es una prueba del menu.");
        print("Pulse X para salir u otra tecla para repetir el mensaje.");
        
        std::cin.get(option);

        if (option == 'c') {
            std::system("cls");
            print(_presenter->sellerDoSomething());
            waitForKey();
        }
    } while ((option != 'x') || (option != 'x'));
}

void View::waitForKey() {
    print("Presione una tecla para continuar.");
    std::cin.get();
    std::cin.ignore();
}