#include "Store.h"

Store::Store(std::string name, std::string address) : _name(name), _address(address) {
}

Store::~Store() {
    this->_garments.clear();
    this->_sellers.clear();
}

void Store::addSeller(Seller &seller) {
    this->_sellers.push_front(seller);
}

void Store::addGarment(Garment *garment) {
    this->_garments.push_front(garment);
}
