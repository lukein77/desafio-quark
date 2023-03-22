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
    public:
        Presenter(IView *view);
        ~Presenter();
        const std::string sellerDoSomething();
        const std::string getStoreName() const { return _store->getName(); }
        const std::string getStoreAddress() const { return _store->getAddress(); }
};

#endif  // _PRESENTER_H_DEFINED_