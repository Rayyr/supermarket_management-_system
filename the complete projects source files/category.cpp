#include "category.h"

category::category() {

	this->num_of_cat = 0;
	this->start = NULL;
};


int category::numof_cat() const{

	return this->num_of_cat;
};


void category::operator+(cat_node& x) {

	// in case that no category has been added yet to the menue 
	if (this->start == NULL) { 
		this->start = new cat_node(x.get_name(), x.get_count());
		this->num_of_cat++;
		return;
	}

	cat_node* follower = this->start;
	while (follower->next != NULL) {
		follower = follower->next;
	}


     follower->next = new cat_node(x.get_name(), x.get_count());
	 this->num_of_cat++;
	 return;
 

};



category::~category() {

	// we will destroy each node in the category linked list , since each one is not 
	// a static obj but is about a dynamic one ( declared by pointer ) 
	cat_node* follow = this->start;
	cat_node* ptr;
 

	while (follow != NULL) {
		ptr = follow->next;
		delete follow;
		follow = ptr;
	}

	// here no need to reset the num of nodes to 0 , because the obj of category 
	// class is go out of the scope , so it cant be used again
};


ostream& operator<<(std::ostream& out, const category& obj) {

	cat_node* ptr = obj.start;

	if (ptr == NULL) {
		out << "SORRY , YOU DONT HAVE ANY CATEGORIES IN THE MARKET , ITS EMPTY ! \n";
		return out;
	}

	out << "THIS IS THE CURRENT CATEGORIES ARE EXIST IN THE MARKET : \n";

	while (ptr != NULL) {

		out << ptr->get_name() << " " << ptr->get_count();
		out << endl;
		ptr = ptr->next;

	}

	return out;
};



string category::get_cat_name() const {

	return this->start->get_name(); // always will return the first category name 
	 // because start pointer is fixed at the start of the linked list
};



cat_node* category::get_start() const{

	return this->start;
};



cat_node* category::search(string category) {
	cat_node* ptr = this->start;

	while (ptr != NULL) {
		if (ptr->get_name() == category) {
			return ptr;
		}
		ptr = ptr->next;
	}

	//in case that the given category name not found in the market
	return NULL;
};



void category::set_num_of_cat(int x) {
	this->num_of_cat--;
	return;
};


void category::remove_cat(cat_node* p) {

	cat_node* p2 = this->start;

	if (p2 == p)//that means the 1st cat in cat list as same as the gone-out cat ( which need to be removed from the menu ) 
	{
		this->start = this->start->next;

	}

	else {
		while (p2->next != p) {//impossible to reach null because the cat is exist 

			p2 = p2->next;
		}
		p2->next = p2->next->next; // or = p.next
		p->next = NULL;
	}


	delete p;
	this->set_num_of_cat(this->numof_cat() - 1);

	return;
};