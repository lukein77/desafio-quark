#ifndef _STORE_H_DEFINED_
#define _STORE_H_DEFINED_

#include <string>
#include <list>
#include "Garment.h"
#include "Seller.h"

class Store {
    private:
        std::string _name;
        std::string _address;
        std::list<Garment*> _garments;
        std::list<std::reference_wrapper<Seller>> _sellers;
    public:
        Store(std::string name, std::string address);
        ~Store();
        void addSeller(Seller &seller);
        void addGarment(Garment *garment);
        
};

#endif