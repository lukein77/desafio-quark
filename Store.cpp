#include "Store.h"
#include <stdexcept>
#include <fstream>

Store::Store(std::string name, std::string address) : _name(name), _address(address) {
}

Store::~Store() {
    this->_garments.clear();
}

void Store::addGarment(Garment *garment) {
    this->_garments.push_back(garment);
}

Garment *Store::getGarmentAt(int index) const {
    try {
        return this->_garments.at(index);
    } 
    catch (const std::out_of_range &e) {
        return nullptr;
    } 
}

void Store::loadStock() {
    std::vector<int> stockVector;
    // Cargar el stock de prendas del archivo
    std::ifstream input("store.bin", std::ios::binary);
    if (!input.fail()) {
        int stock;
        while (input.read(reinterpret_cast<char*>(&stock), sizeof(stock))) {
            stockVector.push_back(stock);
        }
        input.close();
        // Actualizar el stock interno
        int n = stockVector.size();
        for (int i = 0; i < n; i++) {
            _garments.at(i)->setStock(stockVector.at(i));
        }
    }
}

void Store::saveStock() {
    std::ofstream output("store.bin", std::ios::binary);
    int stock;
	for (auto g : _garments) {
        stock = g->getStock();
  		output.write(reinterpret_cast<const char*>(&stock), sizeof(stock));
	}
	output.close();
}