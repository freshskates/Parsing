#pragma once
#include "../controller/dictionary.h"

class Panel {
private: 
	enum Flags {info = 1, help = 2, notFound = 4, prompt = 8, quit = 16};

	void status(int flag);
	void option(const string&, int&);
	void print(string&);
	void error(int, string);
	short int count{ 0 };
	Dictionary& temp;
	vector<Definition> display;
	vector<string> options{ "!q", "!help", "distinct", "reverse" };
	vector<string> partOfSpeeches { "noun", "verb", "adverb", "adjective", "pronoun", "preposition", "conjunction", "interjection" };
public:
	Panel(Dictionary& storage) :temp(storage) {}
	void run();
};