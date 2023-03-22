#include "Shirt.h"

/* Shirt class */
Shirt::Shirt(Quality *quality, double unitPrice, int stock, Neck *neck) :
    Garment(quality, unitPrice, stock), 
    _neck(neck) {}

Shirt::~Shirt() {
    delete _neck;
}

/***************/


/* ShortSleeveShirt class */
ShortSleeveShirt::ShortSleeveShirt(Quality *quality, double unitPrice, int stock, Neck *neck) :
    Shirt(quality, unitPrice, stock, neck) {}


double ShortSleeveShirt::calculatePrice()
{
    return (_quality->calculatePrice(_neck->calculatePrice(_unitPrice * MODIF_SHORTSLEEVE)));
}

/************************/


/* LongSleeveShirt class */

LongSleeveShirt::LongSleeveShirt(Quality *quality, double unitPrice, int stock, Neck *neck) :
    Shirt(quality, unitPrice, stock, neck) {}

double LongSleeveShirt::calculatePrice()
{
    return (_quality->calculatePrice(_neck->calculatePrice(_unitPrice)));
}

/************************/