#ifndef _VENDEDOR_H_DEFINED_
#define _VENDEDOR_H_DEFINED_

#include <string>
#include <list>
#include "Quotation.h"

class Seller {
    private:
        std::string _name;
        std::string _surname;
        int _sellerCode;
        std::list<Quotation> _history;

    public:
        Seller();
        ~Seller();

};

#endif