#pragma once
#include<bits/stdc++.h>
using namespace std;

class product
{
private:
	string pro_name;
	int quantity;
	float price;


public:
	product(string pro_name, float price, int quantity);

	// here we cant set a non-parameterized constructor ( logically ) 
	
	void set_price(float price);
	void set_pro_name(string pro_name);
	void set_quantity(int quantity);

	string get_name() const ;
	int get_quantity() const;
	float get_price() const;

	~product();//no need for override it because we dont have manual pointers
	friend ostream& operator<<(std::ostream& out, const product& obj);
	// print out the product details on the CMD
};

