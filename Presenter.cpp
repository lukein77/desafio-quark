#include "Presenter.h"
#include "Store.h"
#include "Seller.h"
#include "Quotation.h"
#include "Shirt.h"
#include "Trousers.h"
#include <stdexcept>
#include <fstream>
#include <cereal/archives/binary.hpp>

Presenter::Presenter(IView *view)
{
    this->_view = view;
    _store = new Store("Casa de ropa", "25 de mayo 1810");
    loadGarmentList();
    _store->loadStock();
    loadSeller();
}

Presenter::~Presenter() {
    saveSeller();
    _store->saveStock();
    delete _store;
    delete _seller;
}

const std::list<Quotation> Presenter::getSellerHistory() {
    return _seller->getHistory();
}

const std::vector<Garment*> Presenter::getGarmentList() const {
    return (_store->getGarmentList());
}

bool Presenter::validateGarmentIndex(int index) const {
    return (_store->getGarmentAt(index-1) != nullptr);
}

int Presenter::stringToInteger(std::string s) {
    try {
        return std::stoi(s);
    } 
    catch (const std::invalid_argument &e) {
        return -2;
    } 
    catch (const std::out_of_range &e) {
        return -3;
    }
}

double Presenter::stringToDouble(std::string s) {
    try {
        return std::stod(s);
    } 
    catch (const std::invalid_argument &e) {
        return -2;
    } 
    catch (const std::out_of_range &e) {
        return -3;
    }
}

const std::string Presenter::getGarmentName(int index) const {
    return (_store->getGarmentAt(index-1)->toString());
}

const int Presenter::getGarmentStock(int index) const {
    return (_store->getGarmentAt(index-1)->getStock());
}

bool Presenter::setGarmentUnitPrice(int index, double price) {
    return (_store->getGarmentAt(index-1)->setUnitPrice(price));
}

bool Presenter::makeQuotation(int index, int number) {
    Garment *g = _store->getGarmentAt(index-1);
    if (g->updateStock(number)) {
        Quotation q(_seller->getCode(), g, number);
        _seller->addQuotation(q);
        return true;
    } else {
        return false;
    }
}

void Presenter::saveSeller() {
    std::ofstream output("seller.bin", std::ios::binary);

    // Guardar la informacion del vendedor
    cereal::BinaryOutputArchive output_archive(output);
    output_archive(*_seller);

    output.close();
}

void Presenter::loadSeller() {

    std::ifstream input("seller.bin", std::ios::binary);
    if (input.fail()) {
        // No existe el archivo. Debo crear un nuevo vendedor
        _seller = new Seller("Juan", "Perez", 1);
    } else {
        // Cargar el archivo del vendedor y los datos guardados
        _seller = new Seller();
        cereal::BinaryInputArchive input_archive(input);
        input_archive(*_seller);

        input.close();
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