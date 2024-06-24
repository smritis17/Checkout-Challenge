# Checkout Challenge
Problem: Design a checkout that calculates the total receipt and all item information.

Items are stored with their unit price.
Some items are eligible for discounts based on the following 2 deal types: 
- buy 3 identical items and pay for 2
- buy 3 (in a set of items) and the cheapest is free
# Inputs
Provide an array of item_ids to the checkout function

# Outputs
Printing a customer receipt

# Assumptions
Includes all of the assumptions made when creating this program.

# Billing_item.h
Structure for each product billed:
- product name
- unique id of product
- unit price of product
- quantity of same product that is billed
- quantity of product that is discounted

Includes get and set methods for Billing_item object
# Product.h
Structure for each product in the Supermarket:
- product name
- unique id of product
- unit price of product
- group id for any promotions (if included) -> 0 if there's no promotion

Includes get and set methods for Product object

# Billings
Methods
- .add_billing_item : Updates the quantity of each item being billed into the list of items billed
- .exceptions : Checks through billing list to consider for discounts -> 3 of a kind. This simultaneously sorts the items based on group_id
- .exception2_discounts : Sorts the list by price for each group_id and applies the discounts based on sets
- .print_billing_list : Prints the customer receipt -> OUTPUT



# Potential Future Improvements
- Creating methods to change the groupings for each product
- Creating a global variable to change the number of identical items for discount/number of items in a set for discount
