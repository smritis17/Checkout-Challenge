#include <iostream>
#include "Billings.h"
#include <iomanip>

extern std::unordered_map<int, Product> total_items;

//filling the billing_list with chosen items
void Billings::billing_quantity(int item_id) {
    int value;
    auto it = billing_list.find(item_id);
    if (it != billing_list.end()) {
        Billing_Item& item = it->second;
        value = item.get_quantity() + 1;
        item.set_quantity(value);
    } else {
        //Assumming product must be in total_items hashmap
        auto it = total_items.find(item_id);
        if (it!= total_items.end()){
            Product& product = it->second;
            Billing_Item newItem(product.get_product_name(), product.get_product_id(), product.get_price(), 1, 0);
            billing_list[item_id] = newItem;
        }
    }
}
//adding discounts for exception 1: three of a kind
void Billings::three_of_a_kind() {
    for (auto& pair : billing_list) {
        Billing_Item& item = pair.second;
        if (item.get_quantity() < 3) {
            continue;
        } else {
            item.set_discounted_quantity(item.get_quantity()/3);
        }
    }
}

void Billings::groupings() {
    for (auto& pair: billing_list) {
        Billing_Item& item = pair.second;
        int count = item.get_quantity() % 3;
        //if there's no products that satisfy exception 2
        if (count == 0) {
            continue;
        } else {
            auto product_it = total_items.find(pair.first);
            if (product_it == total_items.end()){
                continue;
            }
        
            Product& product = product_it ->second;
            int id = product.get_group_id();
            auto it = discount_groups.find(id);
            //regardless of existing or not, the hashmap will add the id and push the product to the group_id specific list
            for (int i =0; i<count; i++) {
                discount_groups[id].push_back(product);
            }
        }
    }
    for (auto& group_pair : discount_groups) {
        std::sort(group_pair.second.begin(), group_pair.second.end(),
        [](const Product& a, const Product& b) {
            return a.get_price() < b.get_price();
        });
    }

    for (auto& group_pair : discount_groups) {
        auto& products = group_pair.second;
        int length = products.size();
        if (length<3) continue;

        int iter = length/3;
        for (int i=0; i<iter; i++) {
            auto& product = products[i];
            auto it = billing_list.find(product.get_product_id());
            if (it!= billing_list.end()) {
                Billing_Item& item = it->second;
                item.set_discounted_quantity(item.get_discounted_quantity() + 1);
            }
        }
    }
}

void Billings::print_groupings() {
    for (const auto& pair : discount_groups) {
       std::cout<<"Group ID:"<<pair.first<<std::endl;
       for (const auto& product: pair.second) {
        std::cout<<"ProductId:" <<product.get_product_id()
                <<", Name: " <<product.get_product_name()
                <<", Price: " <<product.get_price() <<std::endl;
       }
    }
}

//checking whether the billing list is filled/working properly
void Billings::print_billing_list() {
    double total= 0.00;
    for (const auto& pair : billing_list) {
        const Billing_Item& item = pair.second;
        std::cout << "Item: " << item.get_product_name()
                  << ", Quantity: " << item.get_quantity()
                  << ", Price: $" << std::fixed << std::setprecision(2) << item.get_price() << std::endl;
        std::cout << "Discount:  -$" << std::fixed << std::setprecision(2) << item.get_discounted_quantity()*item.get_price() << std::endl;
        total += (item.get_quantity()-item.get_discounted_quantity()) * item.get_price();
    }
    std::cout << "Total Purchase: $" << std::fixed << std::setprecision(2) << total <<std::endl;
}
