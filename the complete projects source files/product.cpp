#include "product.h"

product::product(string pro_name, float price, int quantity) {

	this->price = price;
	this->pro_name = pro_name;
	this->quantity = quantity;
};

  

void product::set_price(float price) {
	this->price = price;
	return;
};



void product::set_pro_name(string pro_name) {
	this->pro_name = pro_name;
	return;
};


void product::set_quantity(int quantity) {
	this->quantity = quantity;
	return;
};


ostream& operator<<(std::ostream& out, const product& obj) {

	out << obj.pro_name << " " << obj.price << " " << obj.quantity << endl;

	return out;
};


string product::get_name() const {
	return this->pro_name;
};



int product::get_quantity() const {
	return this->quantity;
};


product::~product() {
	// the product name obj will be detroyed only 
};


float product::get_price() const {
	return this->price;
};