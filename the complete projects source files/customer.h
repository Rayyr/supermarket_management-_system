#pragma once
#include<bits\stdc++.h>
using namespace std;

class customer
{
private :
	vector<pair<string, int>> basket;
	/* vector of pairs
	* refers to the bought items ( first element in the pair )  and their quantities ( second element in the pair ) 
	* string refers to the bought product name and int to the bought quantity
	* the num of bought products == vector.size() */

	map<string,float>pro_price;

    float money;// the total money
	 

public: 
	customer();
	void add_to_basket(string pro_name, int quantity,float price);
	// add the bought item to the customer basket

	float get_money() const;
	void operator=(string x); // print out the bill for the customer

};

