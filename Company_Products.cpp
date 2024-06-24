#include "Company_Products.h"
#include <iostream>

extern std::unordered_map<int, Product> total_items;

void Company_Products::add_product(std::string name, int id, double price, int group){
    Product new_product(name, id, price, group);
    total_items[id] = new_product;
}

