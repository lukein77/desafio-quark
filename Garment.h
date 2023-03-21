#ifndef _PRENDA_H_DEFINED_
#define _PRENDA_H_DEFINED_

#include "Quality.h"
#include "Neck.h"

// Prenda (clase abstracta)
class Garment {
    protected:
        Quality *_quality;
        double _unitPrice;
        int _stock;
    public:
        virtual double calculatePrice() = 0;
};

// Camisa
class Shirt : public Garment {
    protected: 
        Neck *_neck;
    public:
        virtual double calculatePrice() override;
};

class ShortSleeveShirt : public Shirt {
    public:
        virtual double calculatePrice() override;
};

class LongSleeveShirt : public Shirt {
    public:
        virtual double calculatePrice() override;
};


// Pantalon
class Trousers : public Garment {};

class CommonTrousers : public Trousers {
};

class SkinnyTrousers : public Trousers {
    public:
        virtual double calculatePrice() override;
};

#endif