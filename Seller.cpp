#include "Seller.h"
#include <fstream>
#include <cereal/archives/binary.hpp>

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

void Seller::saveQuotationHistory() {
    // Open a binary file for writing
    std::ofstream output("history.bin", std::ios::binary);

    // Create a binary output archive and serialize the object to it
    cereal::BinaryOutputArchive output_archive(output);
    output_archive(_history);

    // Close the file
    output.close();
}

void Seller::loadQuotationHistory() {
    // Open the binary file for reading
    std::ifstream input("history.bin", std::ios::binary);

    // Create a binary input archive and deserialize the object from it
    cereal::BinaryInputArchive input_archive(input);
    input_archive(_history);

    // Close the file
    input.close();
}