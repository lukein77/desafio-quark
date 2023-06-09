#ifndef _SHIRT_H_DEFINED_
#define _SHIRT_H_DEFINED_

#include "Garment.h"
#include "Neck.h"

#define MODIF_SHORTSLEEVE 0.9    // -10%

// Camisa
class Shirt : public Garment {
    protected: 
        Shirt(Quality *quality, double unitPrice, int stock, Neck *neck);
        Neck *_neck;
    public:
        virtual ~Shirt();
        const std::string toString() override { return "Camisa"; }
};

class ShortSleeveShirt : public Shirt {
    public:
        ShortSleeveShirt(Quality *quality, double unitPrice, int stock, Neck *neck);
        ~ShortSleeveShirt() {}
        double calculatePrice() override;
        const std::string toString() override;
};

class LongSleeveShirt : public Shirt {
    public:
        LongSleeveShirt(Quality *quality, double unitPrice, int stock, Neck *neck);
        ~LongSleeveShirt() {}
        double calculatePrice() override;
        const std::string toString() override;
};

#endif // _SHIRT_H_DEFINED_