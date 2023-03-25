#include "Seller.h"
#include <fstream>
#include <iostream>

Seller::Seller(std::string name, std::string surname, int code) : 
    _name(name), 
    _surname(surname), 
    _sellerCode(code),
    _history() {}

Seller::~Seller() {
    this->_history.clear();
}

void Seller::addQuotation(Quotation quotation) {
    this->_history.push_front(quotation);
}

void Seller::loadQuotations() {
    std::ifstream input("history.bin", std::ios::binary);
    Quotation q;
    q.loadFromFile(input);
    while (!input.eof()) {
        std::cout << q.getId();
        std::cout << q.getTimestamp();
        //_history.push_back(q);
        q.loadFromFile(input);
    }
    input.close();
}

void Seller::saveQuotations() {
    std::ofstream output("history.bin", std::ios::binary);
    for (auto q : _history) {
        q.saveToFile(output);
    }
    output.close();
}
