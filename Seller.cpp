#include "Seller.h"

Seller::Seller(std::string name, std::string surname, int code) : 
    _name(name), 
    _surname(surname), 
    _sellerCode(code) {}

Seller::~Seller() {
    this->_history.clear();
}

void Seller::addQuotation(Quotation &quotation) {
    this->_history.push_front(quotation);
}
