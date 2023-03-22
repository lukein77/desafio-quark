#ifndef _TROUSERS_H_DEFINED_
#define _TROUSERS_H_DEFINED_

#include "Garment.h"

#define MODIF_SKINNYTROUSERS 0.88   // -12%

// Pantalon
class Trousers : public Garment {
    protected:
        Trousers(Quality *quality, double unitPrice, int stock);
    public:
        virtual ~Trousers() {}
};

class CommonTrousers : public Trousers {
    public:
        CommonTrousers(Quality *quality, double unitPrice, int stock);
        ~CommonTrousers() {}
        double calculatePrice() override;
};

class SkinnyTrousers : public Trousers {
    public:
        SkinnyTrousers(Quality *quality, double unitPrice, int stock);
        ~SkinnyTrousers() {}
        double calculatePrice() override;
};


#endif // TROUSERS_H_DEFINED_