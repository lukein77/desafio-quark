#ifndef _PRENDA_H_DEFINED_
#define _PRENDA_H_DEFINED_

#include "Quality.h"

// Prenda (clase abstracta)
class Garment {
    protected:
        Garment(Quality *quality, double unitPrice, int stock);
        Quality *_quality;
        double _unitPrice;
        int _stock;
    public:
        virtual ~Garment();
        virtual double calculatePrice() = 0;
        bool setUnitPrice(const double price);
        bool setStock(const int stock);
        bool updateStock(const int number);
        const int getStock() const { return _stock; }
        
};


#endif