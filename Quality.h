#ifndef _QUALITY_H_DEFINED_
#define _QUALITY_H_DEFINED_

#define MODIF_PREMIUM 1.3   // +30%

class Quality {
    public:
        virtual double calculatePrice(double price) = 0;
};

class StandardQuality : public Quality {
    public:
        double calculatePrice(double price) override { return price; }
};

class PremiumQuality : public Quality {
    public:
        double calculatePrice(double price) override { return price * MODIF_PREMIUM; }
};

#endif  // _QUALITY_H_DEFINED_