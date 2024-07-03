#pragma once
#include "cat_node.h"

// linkedlist implementation of categories

class category
{
private : 

	cat_node* start; // the start of the category linkedlist ( it will be fixed to the start node )
	int num_of_cat;// the categoroes in the menu ( the num of nodes in the market )

public:
	category();
	void operator +(cat_node& x);// add new category
	int numof_cat() const;// return the num of categories in the list
	cat_node* get_start() const;//return the start of the ce=ategory linkedlist
	cat_node* search(string x);// search about given category name if found , then return pointer to it
	void set_num_of_cat(int x);// to decrease the num of category nodes by 1
	void remove_cat(cat_node* p);// to delete a category by the given pointer to it 
	~category();// the destroctor , here we must override it because we have a manual pointer
	friend ostream& operator<<(ostream& out, const category& obj) ;
	/* overload an insertion operator
	 to print out the founded categories on the CMD  */ 




	string get_cat_name() const;

};

