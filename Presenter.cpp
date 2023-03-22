#include "Presenter.h"
#include "Store.h"
#include "Seller.h"
#include "Quotation.h"
#include "Shirt.h"
#include "Trousers.h"

Presenter::Presenter(IView *view) {
    this->_view = view;
    this->_store = new Store("Casa de ropa", "25 de mayo 1810");
    this->_seller = new Seller("Lionel", "Messi", 1);
}

Presenter::~Presenter() {
    delete _store;
    delete _seller;
}

const std::string Presenter::sellerDoSomething() {
    Garment *g = new ShortSleeveShirt(new PremiumQuality(), 100, 120, new CommonNeck());
    Quotation *q = new Quotation(1, g, 20, g->calculatePrice()*20);
    return q->toString();
}
