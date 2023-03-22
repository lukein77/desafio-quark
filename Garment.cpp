#include "Garment.h"

Garment::Garment(Quality *quality, double unitPrice, int stock) :   _quality(quality), 
                                                                    _unitPrice(unitPrice),
                                                                    _stock(stock) {}

Garment::~Garment() {
    delete _quality;
}

bool Garment::setUnitPrice(const double price)
{
    if (price >= 0) {
        this->_unitPrice = price;
        return true;
    } else
        return false;
}

bool Garment::setStock(const int stock) {
    if (stock >= 0) {
        this->_stock = stock;
        return true;
    } else 
        return false;
}

bool Garment::updateStock(const int number) {
    this->_stock -= number;
    return (this->_stock >= 0);
}