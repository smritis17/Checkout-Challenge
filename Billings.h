#ifndef BILLINGS_H
#define BILLINGS_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Billing_Item.h"
#include "Company_Products.h"

class Billings {
    private:
         //list of all items & quantity billed
        std::unordered_map<int, Billing_Item> billing_list;

        //remaining items sorted by promotional group
        std::unordered_map<int, std::vector<Product> > discount_groups;
    public:
        void billing_quantity(int item_id);
        void three_of_a_kind();
        void groupings();
        //testing methods
        void print_billing_list();
        void print_groupings();
};
#endif