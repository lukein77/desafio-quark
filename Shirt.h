#ifndef _SHIRT_H_DEFINED_
#define _SHIRT_H_DEFINED_

#include "Garment.h"
#include "Neck.h"

// Camisa
class Shirt : public Garment {
    protected: 
        Neck *_neck;
    public:
        virtual ~Shirt() {}
};

class ShortSleeveShirt : public Shirt {
    public:
        ~ShortSleeveShirt() {}
        double calculatePrice() override;
};

class LongSleeveShirt : public Shirt {
    public:
        ~LongSleeveShirt() {}
        double calculatePrice() override;
};

#endif // _SHIRT_H_DEFINED_