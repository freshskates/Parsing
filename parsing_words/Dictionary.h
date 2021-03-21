#pragma once
#include <fstream>
#include <map>

struct Definition {
	string POS, meaning; 
	Definition(string&& POS, string&& meaning) :POS(POS), meaning(meaning) {}
	Definition(string& POS, string& meaning) :POS(POS), meaning(meaning) {}
};

struct Word {
	vector<Definition> list; 
	Word(int&& n) { list.reserve(n); }
	Word(int& n)  { list.reserve(n); }
	Word() {}
};

class Dictionary {
public:
	map<string, Word> mapped_words = {};
	
	int definitions = 0;
	
	Dictionary() {};
	
	Dictionary(string& file) : file(file) {}
	
	void read();
	
	static vector<string> split(string& s, string&& delimiter, bool&& grab_word = false);

private:
	string file;

	string trim(string& s, bool&& flag);

	void map_words(string& line);
};