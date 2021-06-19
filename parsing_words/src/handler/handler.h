#pragma once
#include "../controller/Dictionary.h"

class Handler
{
public: 
	static void removedup(vector<Definition>&);
	static void filter(vector<Definition>&, const string&);
	static void reverse_list(vector<Definition>&);

};

