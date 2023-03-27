#include "View.h"
#include "Presenter.h"
//#include "Quotation.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <limits>

/// @brief Constructor de la clase Vista
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
    ignoreLine();
    std::cin.get();
}

/// @brief Descarta el contenido del buffer de entrada para evitar errores al ingresar datos.
void View::ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

/// @brief Muestra el historial de cotizaciones del vendedor.
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

/// @brief Muestra el listado de prendas disponibles.
void View::showGarmentList() {
    std::vector<Garment*> garmentList = _presenter->getGarmentList();
    int n = _presenter->getTotalGarments();
    for (int i = 0; i < n; i++) {
        print(std::to_string(i+1) + ") " + garmentList.at(i)->toString());
    }
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
        ignoreLine();

        if (option == '1') {
            showSellerHistory();
        } 
        else if (option == '2') {
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
    while (true) {
        std::system("cls");
        print("Listado de prendas:");
        showGarmentList();
        
        print("Seleccione el codigo de la prenda a cotizar, o 0 para regresar al menu principal.");

        int garmentCode = getInteger();

        if (garmentCode != 0) {
            validOption = _presenter->validateGarmentIndex(garmentCode);
            
            if (validOption) {
                makeQuotation(garmentCode);
            } else {
                print("Codigo invalido.");
            }
        } else {
            ignoreLine();
            break;
        }
    }
}

/// @brief Muestra el menu para realizar una cotizacion de una prenda elegida.
/// @param garmentCode Codigo de prenda a cotizar
void View::makeQuotation(int garmentCode) {
    std::system("cls");
    std::string option;

    print("Cotizando prenda: ", false);
    print(_presenter->getGarmentName(garmentCode));
    print("Cantidad en stock: ", false);
    print(std::to_string(_presenter->getGarmentStock(garmentCode)));
    
    print("Ingrese el precio unitario de la prenda, o 0 para volver atras:");
    double unitPrice = getDouble();
    if (unitPrice != 0) {
        if (_presenter->setGarmentUnitPrice(garmentCode, unitPrice)) {
            print("Ingrese cantidad a cotizar, o 0 para volver atras:");
            int number = getInteger();
            if (number != 0) {
                if (_presenter->makeQuotation(garmentCode, number)) {
                    print("La cotizacion se realizo correctamente.");
                } else {
                    print("No hay suficientes unidades en stock.");
                }
            }
        }
    }
    waitForKey();
}

/// @brief Pide al usuario ingresar un entero mayor o igual a x.
/// @return Entero mayor o igual a 0
int View::getInteger() {
    while (true) {
        int n;
        std::cin >> n;
        
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            print("Debe ingresar un numero.");
        } else {
            ignoreLine();
            return n;
        }
    }
}

/// @brief Pide al usuario ingresar un numero decimal positivo.
/// @return Numero de punto flotante de doble precision mayor o igual a 0
double View::getDouble() {
   while (true) {
        double n;
        std::cin >> n;
        
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            print("Debe ingresar un numero.");
        } else {
            ignoreLine();
            return n;
        }
    }
}
