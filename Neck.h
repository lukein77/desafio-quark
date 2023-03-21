#ifndef _NECK_H_DEFINED_
#define _NECK_H_DEFINED_

class Neck {
    public:
        virtual double calculatePrice(double price) = 0;
};

class CommonNeck : public Neck {
    public:
        virtual double calculatePrice(double price) override { return price; }
};

class MaoNeck : public Neck {
    public:
        virtual double calculatePrice(double price) override { return price * 0.03; }
};

#endif