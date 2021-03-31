#pragma once
#include "Header.h"
#include <fstream>
#include <unordered_map>

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


//<storage> string string string 
//school name, <storage> 
//abc, def, ghi 
//School Name, School Type, Starting Median Salary, Mid - Career Median Salary, Mid - Career 10th Percentile Salary, Mid - Career 25th Percentile Salary, Mid - Career 75th Percentile Salary, Mid - Career 90th Percentile Salary
//Massachusetts Institute of Technology(MIT), Engineering, "$72,200.00", "$126,000.00", "$76,800.00", "$99,200.00", "$168,000.00", "$220,000.00"


class Dictionary {
public:
	unordered_map<string, Word> mapped_words = {};
	int definitions = 0;
	Dictionary() {};
	Dictionary(string& file) : file(file) {}
	void read();
	static vector<string> split(string& s, string&& delimiter, bool&& grab_word = false);

private:
	string file;
	void map_words(string&);
};
