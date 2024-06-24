#include <iostream>
#include "Billings.h"
#include <iomanip>

extern std::unordered_map<int, Product> total_items;

//filling the billing_list with chosen items
void Billings::add_billing_item(int item_id) {
    int value;
    auto it = billing_list.find(item_id);
    //if the item is found in the billing list, increment the quantity
    if (it != billing_list.end()) {
        Billing_Item& item = it->second;
        value = item.get_quantity() + 1;
        item.set_quantity(value);
    } else {
        //Assumming product must be in total_items hashmap
        //adding the new item into the billing list
        auto it = total_items.find(item_id);
        if (it!= total_items.end()){
            Product& product = it->second;
            Billing_Item newItem(product.get_product_name(), product.get_product_id(), product.get_price(), 1, 0);
            billing_list[item_id] = newItem;
        }
    }
}
//adding discounts for exception 1: three of a kind and exception 2: 3 in one group
void Billings::exceptions() {
    for (auto& pair : billing_list) {
        Billing_Item& item = pair.second;
        if (item.get_quantity() > 3) {
            item.set_discounted_quantity(item.get_quantity()/3);
        }
        int count = item.get_quantity() % 3;
        //if there's no products that satisfy exception 2 after looking at exception 1, skip
        if (count == 0) {
            continue;
        } else {
            auto product_it = total_items.find(pair.first);
            if (product_it == total_items.end()){
                continue;
            }
            Product& product = product_it ->second;
            int id = product.get_group_id();
            if (id == 0) continue;
            //regardless of existing or not, the hashmap will add the id and push the product to the group_id specific list
            for (int i =0; i<count; i++) {
                discount_groups[id].push_back(product);
            }
        }

    }
}

void Billings::exception2_discounts() {
    //sorting each group_id in the discount_groups by price low to high
    for (auto& group_pair : discount_groups) {
        auto& discount_product_item = group_pair.second;
        int length = discount_product_item.size();
        if (length<3) continue;
        //sorts the array for specified group_id after length>3
        std::sort(group_pair.second.begin(), group_pair.second.end(),
        [](const Product& a, const Product& b) {
            return a.get_price() < b.get_price();
        });

        int iter = length/3;
        for (int i=0; i<iter; i++) {
            auto& product = discount_product_item[i];
            auto it = billing_list.find(product.get_product_id());
            if (it!= billing_list.end()) {
                Billing_Item& item = it->second;
                item.set_discounted_quantity(item.get_discounted_quantity() + 1);
            }
        }
    }
}

//OUTPUT!! Printing the receipt
//checking whether the billing list is filled/working properly
void Billings::print_billing_list() {
    double total= 0.00;
    std::cout <<"Customer Receipt" << std::endl;
    std::cout << std::endl;
    for (const auto& pair : billing_list) {
        const Billing_Item& item = pair.second;
        std::cout << item.get_product_name()
                  << ", Price: $" << std::fixed << std::setprecision(2) << item.get_price()* item.get_quantity() << std::endl;
        if (item.get_quantity() >1) {
            std::cout << item.get_quantity()
                << "@ $" << std::fixed << std::setprecision(2) << item.get_price() << std::endl;
        }
        if (item.get_discounted_quantity() != 0) {
            std::cout << "Discount: -$" << std::fixed << std::setprecision(2) << item.get_discounted_quantity()*item.get_price() << std::endl;
        }        
        total += (item.get_quantity()-item.get_discounted_quantity()) * item.get_price();
    }
    std::cout << std::endl;
    std::cout << "Total Purchase: $" << std::fixed << std::setprecision(2) << total <<std::endl;
    std::cout << std::endl;
}
