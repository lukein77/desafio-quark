#ifndef _PRENDA_H_DEFINED_
#define _PRENDA_H_DEFINED_

#include "Quality.h"

// Prenda (clase abstracta)
class Garment {
    protected:
        Quality *_quality;
        double _unitPrice;
        int _stock;
    public:
        virtual ~Garment() {}
        virtual double calculatePrice() = 0;
};


#endif