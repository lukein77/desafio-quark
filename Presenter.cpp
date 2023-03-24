#include "Presenter.h"
#include "Store.h"
#include "Seller.h"
#include "Quotation.h"
#include "Shirt.h"
#include "Trousers.h"
#include <iostream>         // SACAR ESTO

Presenter::Presenter(IView *view)
{
    this->_view = view;
    this->_store = new Store("Casa de ropa", "25 de mayo 1810");
    this->_seller = new Seller("Juan", "Perez", 1);
    this->loadGarmentList();
}

Presenter::~Presenter() {
    delete _store;
    delete _seller;
}

const std::list<Quotation> Presenter::getSellerHistory() {
    return _seller->getHistory();
}

const std::string Presenter::getGarmentList() const {
    int n = _store->getTotalGarments();
    std::string temp = "";
    for (int i = 0; i < n; i++) {
        temp += std::to_string(i) + ") " + _store->getGarmentAt(i)->toString() + "\n";
    }
    return temp;
}

bool Presenter::validateGarmentIndex(int index) const {
    return (_store->getGarmentAt(index) != nullptr);
}

const std::string Presenter::getGarmentName(int index) const {
    return (_store->getGarmentAt(index)->toString());
}

const int Presenter::getGarmentStock(int index) const {
    return (_store->getGarmentAt(index)->getStock());
}

bool Presenter::setGarmentUnitPrice(int index, double price) {
    return (_store->getGarmentAt(index)->setUnitPrice(price));
}

bool Presenter::makeQuotation(int index, int number) {
    Garment *g = _store->getGarmentAt(index);
    if (g->updateStock(number)) {
        Quotation q(_seller->getCode(), g, number);
        _seller->addQuotation(q);
        std::cout << q.toString();
        return true;
    } else {
        return false;
    }
}

void Presenter::loadGarmentList() {
   _store->addGarment(new ShortSleeveShirt(new StandardQuality(), 0, 100, new MaoNeck()));
   _store->addGarment(new ShortSleeveShirt(new PremiumQuality(), 0, 100, new MaoNeck()));
   _store->addGarment(new ShortSleeveShirt(new StandardQuality(), 0, 150, new CommonNeck()));
   _store->addGarment(new ShortSleeveShirt(new PremiumQuality(), 0, 150, new CommonNeck()));

   _store->addGarment(new LongSleeveShirt(new StandardQuality(), 0, 75, new MaoNeck()));
   _store->addGarment(new LongSleeveShirt(new PremiumQuality(), 0, 75, new MaoNeck()));
   _store->addGarment(new LongSleeveShirt(new StandardQuality(), 0, 175, new CommonNeck()));
   _store->addGarment(new LongSleeveShirt(new PremiumQuality(), 0, 175, new CommonNeck()));

   _store->addGarment(new SkinnyTrousers(new StandardQuality(), 0, 750));
   _store->addGarment(new SkinnyTrousers(new PremiumQuality(), 0, 750));
   _store->addGarment(new CommonTrousers(new StandardQuality(), 0, 250));
   _store->addGarment(new CommonTrousers(new PremiumQuality(), 0, 250));
}