#ifndef _QUOTATION_H_DEFINED_
#define _QUOTATION_H_DEFINED_

#include "Garment.h"
#include <string>
#include <cereal/types/string.hpp>
#include <cereal/types/list.hpp>

class Quotation {
    static int id_count;
    private:
        int _id;                // Numero de cotizacion
        int _sellerCode;        // Codigo de vendedor
        std::string _timestamp; // Fecha y hora en que se realizo
        std::string _garment;   // Prenda cotizada
        int _number;            // Cantidad cotizada
        double _unitPrice;      // Precio unitario
        double _finalPrice;     // Precio final
    public:
        Quotation() {}
        Quotation(int sellerCode, Garment *garment, int number);
        ~Quotation() {}
        std::string toString();

        // Serialization function
        template<class Archive>
        void serialize(Archive& ar) {
            ar(_id, _sellerCode, _timestamp, _garment, _number, _unitPrice, _finalPrice);
        }

};

#endif  // _QUOTATION_H_DEFINED_