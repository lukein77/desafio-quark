#ifndef _NECK_H_DEFINED_
#define _NECK_H_DEFINED_

#include <string>

#define MODIF_MAONECK 1.03  // +3%

class Neck {
    public:
        virtual double calculatePrice(double price) = 0;
        virtual const std::string toString() = 0;
};

class CommonNeck : public Neck {
    public:
        double calculatePrice(double price) override { return price; }
        const std::string toString() { return "Cuello comun"; }
};

class MaoNeck : public Neck {
    public:
        double calculatePrice(double price) override { return price * MODIF_MAONECK; }
        const std::string toString() { return "Cuello mao"; }
};

#endif  // _NECK_H_DEFINED_