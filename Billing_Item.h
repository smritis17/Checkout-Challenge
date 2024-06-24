#include <string>
#ifndef BILLING_ITEM_H
#define BILLING_ITEM_H

class Billing_Item {
private:
    std::string product_name;
    int product_id;
    double price;
    int quantity;
    int discounted_quantity;

public:
    Billing_Item(); //base case
    Billing_Item(std::string name, int id, double cost, int count, int discount);
    //get methods
    std::string get_product_name() const;
    int get_product_id() const;
    double get_price() const;
    int get_quantity() const;
    int get_discounted_quantity() const;

    //set methods
    void set_product_name(std::string name);
    void set_product_id(int id);
    void set_price(double cost);
    void set_quantity(int count);
    void set_discounted_quantity(int discount);

};

#endif