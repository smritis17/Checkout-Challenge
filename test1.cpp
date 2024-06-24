#include <string>
#include <iostream>
#include <unordered_map>
#include "Billings.h"
#include "Company_Products.h"


std::unordered_map<int, Product> total_items;

void checkout(const std::vector<int>& purchase) {
    Billings receipt;

    int list_size = purchase.size();
    for (int i = 0; i < list_size; i++) {
        receipt.billing_quantity(purchase[i]);
    }
    receipt.three_of_a_kind();
    receipt.groupings();
    receipt.print_billing_list();
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

    std::vector<int> buying_list = {1, 1, 1, 1, 2, 3, 4};
    checkout(buying_list);
    return 0;

}
