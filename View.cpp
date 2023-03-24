#include "View.h"
#include "Presenter.h"
//#include "Quotation.h"
#include <iostream>
#include <windows.h>

View::View() {
    _presenter = new Presenter(this);
    SetConsoleTitleW(L"Casa de Ropa");
	setlocale(LC_ALL, "es_Es");
    showMainMenu();
}


/// @brief Imprime una linea de codigo por consola.
/// @param text Texto a imprimir
/// @param newline Indica si insertar un salto de linea
void View::print(const std::string &text, bool newline) {
    std::cout << text;
    if (newline) std::cout << std::endl;
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

void View::showSellerHistory() {
    std::system("cls");
    print("Historial de cotizaciones de ", false);
    print(_presenter->getSellerName());
    
    std::list<Quotation> sellerHistory = _presenter->getSellerHistory();
    for (auto q : sellerHistory) {
        print(q.toString());
    }
    waitForKey();
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
            std::cin.ignore();
            showSellerHistory();
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

    bool validOption = false;
    do { 
        std::system("cls");
        print("Seleccione el codigo de la prenda a cotizar, o X para regresar al menu principal.");
        print(_presenter->getGarmentList());

        std::string option;
        std::cin >> option;
        
        if ((option != "x") && (option != "X")) {
            int garmentCode = std::stoi(option);
            validOption = _presenter->validateGarmentIndex(garmentCode);
            
            if (validOption) {
                //std::cout << "Cantidad ingresada: " << option;
                std::cin.ignore();
                makeQuotation(garmentCode);
            } else {
                print("Codigo invalido.");
            }
            waitForKey();
        } else {
            validOption = true; // para salir del while
        }
    } while (!validOption);
    std::cin.ignore();
}

void View::makeQuotation(int garmentCode) {
    std::system("cls");
    std::string option;

    print("Cotizando prenda: ", false);
    print(_presenter->getGarmentName(garmentCode));
    print("Cantidad en stock: ", false);
    print(std::to_string(_presenter->getGarmentStock(garmentCode)));
    
    print("Ingrese el precio unitario de la prenda:");
    std::cin >> option;
    if (_presenter->setGarmentUnitPrice(garmentCode, std::stod(option))) {
        print("Ingrese cantidad a cotizar:");
        std::cin >> option;
        if (_presenter->makeQuotation(garmentCode, std::stoi(option))) {
            print("La cotizacion se realizo correctamente.");
        } else {
            print("Error");
        }
    }
}