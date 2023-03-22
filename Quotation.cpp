#include "Quotation.h"

int Quotation::id_count = 0;

Quotation::Quotation(int sellerCode, Garment *garment, int number, double finalPrice) {
    this->_id = ++id_count;
    this->_sellerCode = sellerCode;
    this->_garment = garment;
    this->_number = number;
    this->_finalPrice = finalPrice;
}

std::string Quotation::toString() {
    return ("COTIZACION NUMERO "+std::to_string(_id) + "\nPRECIO FINAL: " + std::to_string(_finalPrice) + "\n");
}
