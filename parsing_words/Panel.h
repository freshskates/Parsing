#pragma once
#include "Dictionary.h"
#include <algorithm>
#include <numeric>

class Panel {
	Dictionary& temp;
public:

	Panel(Dictionary& storage) :temp(storage) {}
	vector<Definition> display;
	vector<string> options { "distinct", "reverse", "noun", "verb", "adverb", "adjective", "pronoun", "preposition", "conjunction", "interjection" };
	
	void help();
	void start();
	void option(string&);
	void print();
	void sort_list();
	void removedup();
	void filter(string&);
	void reverse_list();
};