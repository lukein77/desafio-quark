#ifndef _SELLER_H_DEFINED_
#define _SELLER_H_DEFINED_

#include <string>
#include <list>
#include "Quotation.h"

class Seller {
    private:
        std::string _name;
        std::string _surname;
        int _sellerCode;
        std::list<std::reference_wrapper<Quotation>> _history;
    public:
        Seller(std::string name, std::string surname, int code);
        ~Seller();
        void addQuotation(Quotation &quotation);
        const std::string getName() const { return _name; }
        const std::string getSurname() const { return _surname; }
        const std::string getFullName() const { return (_name + " " + _surname); }
};

#endif  // _SELLER_H_DEFINED_