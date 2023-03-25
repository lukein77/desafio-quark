#ifndef _QUOTATION_H_DEFINED_
#define _QUOTATION_H_DEFINED_

#include "Garment.h"
#include <string>
#include <fstream>

class Quotation {
    static int id_count;
    private:
        int _id;                // Numero de cotizacion
        int _sellerCode;        // Codigo de vendedor
        std::string _timestamp; // Fecha y hora en que se realizo
        std::string _garment;   // Prenda cotizada
        int _number;            // Cantidad cotizada
        double _unitPrice;      // Precio unitario
        double _finalPrice;     // Precio final
    public:
        Quotation() {}
        Quotation(int sellerCode, Garment *garment, int number);
        ~Quotation() {}
        std::string toString();
        void saveToFile(std::ofstream &output);
        void loadFromFile(std::ifstream &input);
        std::string getTimestamp() { return _timestamp; }
        int getId() { return _id; }

};

#endif  // _QUOTATION_H_DEFINED_