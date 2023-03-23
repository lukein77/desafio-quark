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

/// @brief Imprime una linea de texto en consola
/// @param text El texto a imprimir
void View::print(const std::string &text) {
    std::cout << text << std::endl;
}

/// @brief Queda a la espera de que el usuario presione una tecla para continuar
/// @param showMessage Define si se le pide explicitamente presionar una tecla al usuario o no
void View::waitForKey(bool showMessage) {
    if (showMessage) print("Presione una tecla para continuar.");
    std::cin.get();
    std::cin.ignore();
}


/// @brief Imprime el encabezado del menu principal
void View::showHeader() {
    print("COTIZADOR EXPRESS - MENU PRINCIPAL");
    print("----------------------------------");
    print(_presenter->getStoreName() + " | " + _presenter->getStoreAddress());
    print("----------------------------------");
    print(_presenter->getSellerName());
    print("----------------------------------");
}


/// @brief Imprime el menu principal y las opciones para su navegacion
void View::showMainMenu() {

    char option = '0';
    bool alive = true;
    do {
        std::system("cls");
        showHeader();

        print("1) Ver historial de cotizaciones");
        print("2) Cotizar nueva prenda");
        print("x) Salir");
        
        std::cin.get(option);

        if (option == '1') {
            std::system("cls");
            print(_presenter->sellerDoSomething());
            waitForKey();
        } 
        else if (option == '2') {
            std::cin.ignore();
            showQuotationMenu();
        }
        else if ((option == 'x') || (option == 'X')) {
            print("Vuelva pronto");
            alive = false;
        }
        else {
            print("La tecla ingresada no es valida.");
            waitForKey();
        }
    } while (alive);
}

/// @brief Muestra el menu para realizar una cotizacion
void View::showQuotationMenu() {
    /*std::cin.ignore();
    char option = '0';

    do {
        std::system("cls");
        print("Que prenda desea cotizar?");
        print("1) Camisa");
        print("2) Pantalon");
        print("x) Volver al menu principal");

        std::cin.get(option);

        if (option == '1') {
            print("Cotizo camisa jiji");
            waitForKey();
        }
        else if (option == '2') {
            print("Cotizo pantalon jijiji");
            waitForKey();
        }
    } while ((option != 'x') || (option != 'X'));

    std::cin.ignore();
    showMainMenu();
    */
    std::system("cls");
    print(_presenter->getGarmentList());

    std::string option;
    std::cin >> option;

    print(_presenter->getGarmentAt(std::stoi(option)));

    waitForKey();
}

void View::showShirtQuotationMenu() {
    
}

void View::showTrousersQuotationMenu() {
}

