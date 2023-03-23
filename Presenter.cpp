#include "Presenter.h"
#include "Store.h"
#include "Seller.h"
#include "Quotation.h"
#include "Shirt.h"
#include "Trousers.h"

Presenter::Presenter(IView *view)
{
    this->_view = view;
    this->_store = new Store("Casa de ropa", "25 de mayo 1810");
    this->_seller = new Seller("Lionel", "Messi", 1);
    this->loadGarmentList();
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

const std::string Presenter::getGarmentList() const {
    int n = _store->getTotalGarments();
    std::string temp = "";
    for (int i = 0; i < n; i++) {
        temp += std::to_string(i) + ") " + _store->getGarmentAt(i)->toString() + "\n";
    }
    return temp;
}

const std::string Presenter::getGarmentAt(int index) const {
    Garment *g = _store->getGarmentAt(index);
    if (g) {
        return g->toString();
    } 
    else {
        return "Codigo invalido";
    }
}

void Presenter::loadGarmentList() {
    /*
    new MangaCorta(Standard, MaoNeck, 100)
    new MangaCorta(Premium, MaoNeck, 100)
    new MangaCorta(Standard, CommonNeck, 150)
    new MangaCorta(Premium, CommonNeck, 150)
    new MangaLarga(Standard, MaoNeck, 75)
    new MangaLarga(Premium, MaoNeck, 75)
    new MangaLarga(Standard, CommonNeck, 175)
    new MangaLarga(Premium, CommonNeck, 175)
    new Chupin(Standard, 750)
    new Chupin(Premium, 750)
    new PantalonComun(Standard, 250)
    new PantalonComun(Premium, 250)
    */
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