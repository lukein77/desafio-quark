#ifndef _COTIZACION_H_DEFINED_
#define _COTIZACION_H_DEFINED_

#include "Garment.h"

class Quotation {
    private:
        int _id;
        // fecha_hora
        int _sellerCode;
        Garment *_garment;
        int _number;
        double _result;
    public:
        Quotation();
        ~Quotation();
};

#endif