#ifndef _STORE_H_DEFINED_
#define _STORE_H_DEFINED_

#include <string>
#include <list>
#include <vector>
#include "Garment.h"
#include "Seller.h"
#include <cereal/types/vector.hpp>

class Store {
    private:
        std::string _name;
        std::string _address;
        std::vector<Garment*> _garments;
    public:
        Store(std::string name, std::string address);
        ~Store();
        void addGarment(Garment *garment);
        const std::string getName() const { return _name; }
        const std::string getAddress() const { return _address; }
        const int getTotalGarments() const { return _garments.size(); }
        Garment *getGarmentAt(int index) const;
        const std::vector<Garment*> getGarmentList() const { return _garments; }
        void loadStock();
        void saveStock();
};

#endif