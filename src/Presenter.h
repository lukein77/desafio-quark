#ifndef _PRESENTER_H_DEFINED_
#define _PRESENTER_H_DEFINED_

#include <string>
#include "Store.h"
#include "Seller.h"

#define SELLER_FILE "data/seller.bin"

class IView;
class Quotation;

class Presenter {
    private:
        IView *_view;
        Store *_store;
        Seller *_seller;
        void loadGarmentList();
    public:
        Presenter(IView *view);
        ~Presenter();
        const std::list<Quotation> getSellerHistory();
        const std::string getStoreName() const { return _store->getName(); }
        const std::string getStoreAddress() const { return _store->getAddress(); }
        const std::string getSellerName() const { return _seller->getFullName(); }
        const std::vector<Garment*> getGarmentList() const;
        const int getTotalGarments() const { return _store->getTotalGarments(); }
        bool validateGarmentIndex(int index) const;
        int stringToInteger(std::string s);
        double stringToDouble(std::string s);
        const std::string getGarmentName(int index) const;
        const int getGarmentStock(int index) const;
        bool setGarmentUnitPrice(int index, double price);
        bool makeQuotation(int index, int number);
        void saveSeller();
        void loadSeller();
};

#endif  // _PRESENTER_H_DEFINED_