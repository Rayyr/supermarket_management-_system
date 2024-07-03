#pragma once
#include<bits/stdc++.h>
using namespace std;

class cat_node
{
private:
	string name; // name of the category 
	int count; // its quantity

public:
	cat_node* next;
    cat_node();// the default constructor
	cat_node(string name, int count); // the parameterized constructor
    string get_name() const; // return the category name
	int get_count() const; // return the quantity of the category
	void set_count(int x);// set the quantitty of category
	~cat_node();
	/* the destructor, here its not essential because we dont have
     * manual pointers ( new keyword ) so by default the default destroctor will be
	 * called 
	 * */
};

