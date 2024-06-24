#include "Product.h"

//base cases
Product::Product() : product_name(""), product_id(0), price(0.00), group_id(0) {}

Product::Product(std::string name, int id, double cost, int group) {
    product_name = name;
    product_id = id;
    price = cost;
    group_id = group;
}

//get methods
std::string Product::get_product_name() const {
    return product_name;
}

int Product::get_product_id() const {
    return product_id;
}

double Product::get_price() const {
    return price;
}

int Product::get_group_id() const {
    return group_id;
}

//set methods
void Product::set_product_name(std::string name) {
    product_name = name;
}

void Product::set_product_id(int id) {
    product_id = id;
}

void Product::set_price(double cost) {
    price = cost;
}

void Product::set_group_id(int group) {
    group_id = group;
}