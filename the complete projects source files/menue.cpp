#include "menu.h"

menu::menu(category& x, map<string, vector<product>>& y) {
	this->cat = &x;
	this->pro = &y;
	/* we put the addreasing operator because they are a reference not a direct pointer
	* because in the main cpp file i have declare them as objs not as pointers*/
};


void menu::show_cat() const {

	cout << *this->cat;
	/* i have put the dereferencing operator *, because in the overloaded fun(in category)
	* class the econd parameter must be passed as reference and as we know the reference
	* as same as value */

	return;
};



void menu::show_pro() const {

	cout << "THIS IS THE CURRENT PRODUCTS ARE EXIST IN THE MARKET : \n";

	for (auto x : *this->pro) {
		for (int c = 0; c < x.second.size(); c++)
			cout << x.second[c];//call the overloaded << operator in the product class
		cout << endl;
	}
};


void menu::show_menu() const {

	cat_node* f = this->cat->get_start();//the start of the category linked list

	auto x = *this->pro;

	if (f == NULL) {
		cout << "SORRY , YOUR MARKET IS EMPTY \n";
		// nothing to show
		return;
	}

	cout << "THIS IS THE COMPLETE MENUE : \n";

	for (int j = 0; j < this->cat->numof_cat(); j++) { // num of category are exist
		cout << f->get_name();// name of category
		string h = f->get_name();
		cout << endl;
		// print out the products for the (h) category
		for (int c = 0; c < f->get_count(); c++) {
			cout << x[h][c]; // because its a map of string and vector of products objs

		}

		f = f->next;
		cout << endl;
	}

	return;
};


void menu::show_menu_of_pro(string category) {
	/* impossiple to enter this control(if) statement, because when the product
	* quantity reaches 0 we will remove it from the vector of products of
	* this category , the same if the products of this cat =0 we will remove
	* this category (from the linked list ) from the market menu */

	/* if (this->pro->size() == 0) { // this is the size of map obj
		cout << "SORRY , " << category << " PRODUCTS ARE FINISHED !\n";
	return;
	} */

	cout << "THIS IS THE " << category << " PRODUCTS ARE FOUND IN THE MARKET \n";

	for (auto x : *this->pro) {
		if (x.first == category) {
			for (int c = 0; c < x.second.size(); c++) {
				cout << x.second[c];
			}
		}
	}

	return;
};



void menu::show_menu(string category) {

	cat_node* p = this->cat->search(category);

	if (p == NULL) {
		cout << "SORRY THE CATEGORY " << category << " IS NOT AVALABLE NOW IN THE SUPERMARKET";
		return;//the category not found
	}


	this->show_menu_of_pro(category);
	return;
};



bool menu::decrease(string cat, string pro_name, int quantity) {

	// we gurantee that the choosen product is found in the market , simply because the user choose
	map<string, vector<product>>::iterator x = this->pro->begin();
	vector<product>::iterator v;

	while (x != this->pro->end()) {
		if (x->first == cat) {
			for (v = x->second.begin(); v != x->second.end(); v++) { // start search in the vector of products in the map
				if (v->get_name() == pro_name) {

					if (quantity > v->get_quantity()) { 
						// purchase will be failed if the choosen quantity is greater than the avalable one in the market 
						return false;
					}

					// change the quantity of the product
					v->set_quantity(v->get_quantity() - quantity);

					if (v->get_quantity() == 0) {
						// this product is just finished ( its quantity gone out ) 
						x->second.erase(v);
						cat_node* p = this->cat->search(cat);
						p->set_count(p->get_count() - 1);

						// to check if we still have products from this category 
						//else we will remove this category from the menu

						if (p->get_count() == 0) { // like sweets 0
							this->cat->remove_cat(p);
						}
					}
					// the purchase success
					return true;

				}
			}
		}
		x++;
	}

};



float menu::show_price_of_pro(string pro_name, string cat) {
	// we gurntee that the choosen product is exist because the user choose
	map<string, vector<product>>::iterator it = this->pro->find(cat);

	for (vector<product>::iterator v = it->second.begin(); v != it->second.end(); v++) {
		if (v->get_name() == pro_name) {
			return v->get_price();
		}
	}
	 
};


// this function only for the design and data hiding because in the main cpp only we will 
// deal with menue obj , and through it we will access the category list and products objs
bool menu::search_cat(string cat) {

	if (this->cat->search(cat) == NULL)
		return false;
	return true;
};



bool menu::is_empty() {
	return (this->cat->numof_cat() == 0);
};