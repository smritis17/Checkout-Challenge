#include "Billing_Item.h"
//default constructor
Billing_Item::Billing_Item() : product_name(""), product_id(0), price(0.0), quantity(0), discounted_quantity(0) {}

Billing_Item::Billing_Item(std::string name, int id, double cost, int count, int discount) {
    product_name = name;
    product_id = id;
    price = cost;
    quantity = count;
    discounted_quantity = discount;
}
    


//get methods
std::string Billing_Item::get_product_name() const {
    return product_name;
}

int Billing_Item::get_product_id() const {
    return product_id;
}

double Billing_Item::get_price() const {
    return price;
}

int Billing_Item::get_quantity() const {
    return quantity;
}

int Billing_Item::get_discounted_quantity() const {
    return discounted_quantity;
}

//set methods
void Billing_Item::set_product_name(std::string name) {
    product_name = name;
}

void Billing_Item::set_product_id(int id) {
    product_id = id;
}

void Billing_Item::set_price(double cost) {
    price = cost;
}

void Billing_Item::set_quantity(int count) {
    quantity = count;
}

void Billing_Item::set_discounted_quantity(int discount) {
    discounted_quantity = discount;
}
