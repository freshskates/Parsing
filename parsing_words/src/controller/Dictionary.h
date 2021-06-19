#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Definition {
	string POS, meaning; 
	Definition(string&& POS, string&& meaning) :POS(POS), meaning(meaning) {}
	Definition(string& POS, string& meaning) :POS(POS), meaning(meaning) {}
};

struct Word { 
	//Word(int n) :list(n) {} 
	vector<Definition> list; 
	Word(const int&& n) { list.reserve(n); }
	Word(const int& n) { list.reserve(n); }
	Word() = default; 
};

class Dictionary {
	string file;
	void map_words(string&);
public:
	unordered_map<string, Word> mapped_words;
	int definitions{0};
	Dictionary() {};
	Dictionary(string& file) : file(file) {}
	void read();	
	static vector<string> split(string& s, const string&& delimiter, const bool&& grab_word = false);
};
