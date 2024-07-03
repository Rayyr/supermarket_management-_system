#include "cat_node.h"

#define NULL 0;

cat_node::cat_node() {
	this->name = " ";
	this->count = 0;
	this->next = NULL;
};

cat_node::cat_node(string name, int count) {
	this->name = name;
	this->count = count;
	this->next = NULL;
};


string cat_node::get_name() const {
	return this->name;
};



int cat_node::get_count() const {
	return this->count;
};


cat_node::~cat_node() {
	// the string name obj will be destroyed
};


void cat_node::set_count(int x) {
	this->count = x;
	return;
};