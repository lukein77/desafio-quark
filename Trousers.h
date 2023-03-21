#ifndef _TROUSERS_H_DEFINED_
#define _TROUSERS_H_DEFINED_

#include "Garment.h"

// Pantalon
class Trousers : public Garment {
    public:
        virtual ~Trousers() {}
};

class CommonTrousers : public Trousers {
    public:
        ~CommonTrousers() {}
        double calculatePrice() override;
};

class SkinnyTrousers : public Trousers {
    public:
        ~SkinnyTrousers() {}
        double calculatePrice() override;
};


#endif // TROUSERS_H_DEFINED_