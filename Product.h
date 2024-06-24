#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>

class Product {
    private:
        std::string product_name;
        int product_id;
        double price;
        int group_id;

    public:
        //base
        Product();
        Product(std::string name, int id, double cost, int group);
        

        //get methods
        std::string get_product_name() const;
        int get_product_id() const;
        double get_price() const;
        int get_group_id() const;

        //set methods
        void set_product_name(std::string name);
        void set_product_id(int id);
        void set_price(double cost);
        void set_group_id(int group);
};
#endif