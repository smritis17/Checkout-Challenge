#include <string>
#include <iostream>
#include <unordered_map>
#include "Billings.h"
#include "Company_Products.h"


std::unordered_map<int, Product> total_items;

void checkout(const std::vector<int>& purchase) {
    Billings* receipt = new Billings();

    int list_size = purchase.size();
    for (int i = 0; i < list_size; i++) {
        receipt->add_billing_item(purchase[i]);
    }
    receipt->exceptions();
    receipt->exception2_discounts();
    receipt->print_billing_list();

    delete receipt;
}

int main() {
    // Setup products into store
    Company_Products store;
    store.add_product("Apples", 1, 3.78, 1);
    store.add_product("Mangoes", 2, 2.08, 1);
    store.add_product("Bananas", 3, 5.20, 1);
    store.add_product("Soap", 4, 10.98, 2);
    store.add_product("Cleanser", 5, 12.90, 2);
    store.add_product("Shampoo", 6, 10.78, 2);
    store.add_product("Makeup", 7, 12.39, 0);
    store.add_product("Contact Solution", 8, 10.12, 0);

    //checkout items as a customer
    std::vector<int> buying_list = {1, 1, 1, 1, 2, 3, 4, 7, 7, 8};
    checkout(buying_list);

    std::vector<int> buying_list2 = {6, 6, 6, 6, 5, 5, 7, 8, 8};
    checkout(buying_list2);
    return 0;

}
