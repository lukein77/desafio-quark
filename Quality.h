#ifndef _QUALITY_H_DEFINED_
#define _QUALITY_H_DEFINED_

#include <string>

#define MODIF_PREMIUM 1.3   // +30%


class Quality {
    public:
        virtual double calculatePrice(double price) = 0;
        virtual const std::string toString() = 0;
};

class StandardQuality : public Quality {
    public:
        double calculatePrice(double price) override { return price; }
        const std::string toString() { return "Calidad Estandar"; }
};

class PremiumQuality : public Quality {
    public:
        double calculatePrice(double price) override { return price * MODIF_PREMIUM; }
        const std::string toString() { return "Calidad Premium"; }
};

#endif  // _QUALITY_H_DEFINED_