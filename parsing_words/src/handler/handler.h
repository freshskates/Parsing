#pragma once
#include "../controller/dictionary.h"

class Handler
{
public: 
	static void removedup(vector<Definition>&);
	static void filter(vector<Definition>&, const string&);
	static void reverse_list(vector<Definition>&);
	static void sort_list(vector<Definition>&);
};

