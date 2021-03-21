#pragma once
#include "Dictionary.h"
#include <algorithm>
#include <numeric>

class Panel {
public:

	Dictionary& temp;
	
	Panel(Dictionary& storage) :temp(storage) {}
	
	vector<Definition> display;
	
	vector<string> options = { "distinct", "reversed", "noun", "verb", "adverb", "adjective", "pronoun", "preposition", "conjunction", "interjection" };
	
	void help();

	void start();

	void option(string& check);

	void print();

	void sort_list();
	
	void removedup();
	
	void filter(string& pos);

	void reverse_list();
};