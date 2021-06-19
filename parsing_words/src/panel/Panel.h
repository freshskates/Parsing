#pragma once
#include "../controller/Dictionary.h"
#include <algorithm>
#include <numeric>

class Panel {
	enum Flags {info = 1, help = 2, notFound = 4, prompt = 8, quit = 16};

	void status(int flag);
	void option(const string&);
	void print();
	short int count{ 0 };
	Dictionary& temp;
	vector<Definition> display;
	vector<string> options { "distinct", "reverse", "noun", "verb", "adverb", "adjective", "pronoun", "preposition", "conjunction", "interjection" };
public:
	Panel(Dictionary& storage) :temp(storage) {}
	void run();
};