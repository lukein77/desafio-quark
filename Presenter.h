#ifndef _PRESENTER_H_DEFINED_
#define _PRESENTER_H_DEFINED_

#include <string>
#include "Store.h"
#include "Seller.h"

class IView;
class Seller;

class Presenter {
    private:
        IView *_view;
        Store *_store;
        Seller *_seller;
        void loadGarmentList();
    public:
        Presenter(IView *view);
        ~Presenter();
        const std::string sellerDoSomething();
        const std::string getStoreName() const { return _store->getName(); }
        const std::string getStoreAddress() const { return _store->getAddress(); }
        const std::string getSellerName() const { return _seller->getFullName(); }
        const std::string getGarmentList() const;
        const std::string getGarmentAt(int index) const;
};

#endif  // _PRESENTER_H_DEFINED_