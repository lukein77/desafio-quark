#include "Quotation.h"
#include <ctime>


int Quotation::id_count = 0;

Quotation::Quotation(int sellerCode, Garment *garment, int number) {
    this->_id = ++id_count;     // Identificacion de cotizacion

    // Fecha y hora de la cotizacion (change this shit asap)
    time_t now = time(0);
	tm *localTime = localtime(&now);

    char buffer[24];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", localTime);
    this->_timestamp = std::string(buffer);
    
    this->_sellerCode = sellerCode;
    this->_garment = garment->toString();
    this->_unitPrice = garment->getUnitPrice();
    this->_number = number;
    this->_finalPrice = garment->calculatePrice() * number;
}

std::string Quotation::toString() {
    std::string msg =
        "ID Cotizacion: "+std::to_string(_id)+
        "\nFecha y hora: "+_timestamp+
        "\nCodigo de vendedor: "+std::to_string(_sellerCode)+
        "\nPrenda cotizada: "+_garment+
        "\nPrecio unitario: $"+std::to_string(_unitPrice)+
        "\nCantidad cotizada: "+std::to_string(_number)+
        "\nPrecio final: $"+std::to_string(_finalPrice)+"\n";
    return msg;
}