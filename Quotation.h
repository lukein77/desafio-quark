#ifndef _QUOTATION_H_DEFINED_
#define _QUOTATION_H_DEFINED_

#include "Garment.h"
#include <string>

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
        Quotation(int sellerCode, Garment *garment, int number);
        ~Quotation() {}
        std::string toString();

};

#endif  // _QUOTATION_H_DEFINED_