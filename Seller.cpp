#include "Seller.h"
#include <fstream>

Seller::Seller(std::string name, std::string surname, int code) : 
    _name(name), 
    _surname(surname), 
    _sellerCode(code),
    _quotations(0),
    _history() {}

Seller::~Seller() {
    this->_history.clear();
}

void Seller::addQuotation(Quotation quotation) {
    this->_history.push_front(quotation);
    _quotations++;
}
