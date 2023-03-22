#include "Trousers.h"

/* Trousers class */
Trousers::Trousers(Quality *quality, double unitPrice, int stock) :
    Garment(quality, unitPrice, stock) {}
/******************/

/* CommonTrousers class */
CommonTrousers::CommonTrousers(Quality *quality, double unitPrice, int stock) : 
    Trousers(quality, unitPrice, stock) {}


double CommonTrousers::calculatePrice()
{
    return (_quality->calculatePrice(_unitPrice));
}
/***********************/

/* SkinnyTrousers class */
SkinnyTrousers::SkinnyTrousers(Quality *quality, double unitPrice, int stock) :
    Trousers(quality, unitPrice, stock) {}

double SkinnyTrousers::calculatePrice()
{
    return (_quality->calculatePrice(_unitPrice * MODIF_SKINNYTROUSERS));
}

/************************/
