#ifndef _NECK_H_DEFINED_
#define _NECK_H_DEFINED_

#define MODIF_MAONECK 1.03  // +3%

class Neck {
    public:
        virtual double calculatePrice(double price) = 0;
};

class CommonNeck : public Neck {
    public:
        double calculatePrice(double price) override { return price; }
};

class MaoNeck : public Neck {
    public:
        double calculatePrice(double price) override { return price * MODIF_MAONECK; }
};

#endif  // _NECK_H_DEFINED_