#include<string>

class Promo_Group {
    private:
        std::string group_name;
        int group_id;

    public:
        //constructing promotional groups
        Promo_Group(std::string name, int group){
            group_name = name;
            group_id = group;
        }

        //get methods
        std::string get_group_name() const {
            return group_name;
        }

        int get_group_id() const {
            return group_id;
        }

        //set methods
        void set_product_name(std::string name) {
            group_name = name;
        }

        void set_group_id(int group) {
            group_id = group;
        }
};