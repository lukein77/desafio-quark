#ifndef _QUOTATION_H_DEFINED_
#define _QUOTATION_H_DEFINED_

#include "Garment.h"

class Quotation {
    private:
        int _id;            // Numero de cotizacion
        int _sellerCode;    // Codigo de vendedor
        // fecha_hora   
        Garment *_garment;  // Prenda cotizada
        int _number;        // Cantidad cotizada
        double _finalPrice;     // Precio final
    public:
        Quotation(int sellerCode, Garment *garment, int number, double finalPrice);
        ~Quotation();
};

#endif  // _QUOTATION_H_DEFINED_