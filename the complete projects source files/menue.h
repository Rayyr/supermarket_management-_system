#pragma once
#include"category.h"
#include"product.h"

/* here the menue class, contain the principle of composition, in other words, in fact
* the menue consist of list of categories and each category consist of list of products 
* with their own details */

class menu 
{
private: 

	category* cat; // pointer to the category obj linked list
	map<string, vector<product>>*pro;// the products for each category
	// we made them as pointers to gurantee any edit proccess to be saved 
	
    // private functions 
	void show_menu_of_pro(string category);//print out the products for specefic given category 

public:
	 

	menu(category& x, map<string, vector<product>>& y);// to set up the market menue
	void show_cat() const;// print out the available categories in the market
	void show_pro() const;// print out the avalable products in the market based to the categories
	void show_menu() const;// print out the entry menu of the market
	void show_menu(string category);//print out the products for specefic given category 
	bool decrease(string cat, string pro_name,int quantity);
	// to decrease the quantity of the choosen product from the market
	float show_price_of_pro(string pro_name,string cat);//return the price for choosen product
	bool search_cat(string cat);//for design not more than that --its explained in details in the cpp file for menu class--
	bool is_empty();//check if the market is empty or not
	 

};

