#ifndef COMPANY_PRODUCTS_H
#define COMPANY_PRODUCTS_H

#include <string>
#include <unordered_map>
#include "Product.h"

class Company_Products {

    public:

        void add_product(std::string name, int id, double price, int group);
};

#endif