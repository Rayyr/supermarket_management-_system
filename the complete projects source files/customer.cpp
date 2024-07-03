#include "customer.h"

customer::customer() {

	this->money = 0.0f; // no bought prodects yet
};


void customer::add_to_basket(string pro_name, int quantity, float price) {

	//to check if the customer buy  this product previously
	// in this case we gurntee that all of the vector elements are ideal 

	vector<pair<string, int>>::iterator it;

	for (it = this->basket.begin(); it != this->basket.end(); it++) {
		if (it->first == pro_name) {
			it->second += quantity;
			this->money += quantity * price;
			this->pro_price[it->first] += quantity * price;
			return;

		}
	}


	this->basket.push_back(make_pair(pro_name, quantity));
	this->money += quantity * price;
	this->pro_price.insert(make_pair(pro_name, price * quantity));

	return;
};



float customer::get_money() const {
	return this->money;
};

 

void customer::operator=(string x) {

	if (x == "show customer bill on cmd") {

		// we will print the basket in the following format : 
		// product name         quantity          price

		cout << "PRODUCT\t\tQUANTITY\tPRICE" << endl;
		for (int c = 0; c < this->basket.size(); c++) {
			cout << this->basket[c].first << "\t\t" << this->basket[c].second << "\t\t" << this->pro_price[this->basket[c].first] << endl;
		}
		cout << "\nTHE TOTAL MONEY TO PAY = " << this->get_money() << endl;
	}


	else 
		if(x== "show customer bill on file") {

		FILE* out; // file handling in c lang.

		out = fopen("bill.txt", "w");

		fprintf(out, "PRODUCT\t\tQUANTITY\tPRICE\n");

		for (int c = 0; c < this->basket.size(); c++) {

			fprintf(out, "%s\t\t%d\t\t%f\n", this->basket[c].first.c_str(), this->basket[c].second, this->pro_price[this->basket[c].first]);

		}

		fprintf(out, "\nTHE TOTAL MONEY TO PAY = %f\n", this->get_money());

		fclose(out);
	}

	return;
};