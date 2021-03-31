#include "Dictionary.h"
#include <fstream>

	void Dictionary::read() {
		string line;
		ifstream fin;
		fin.open(this->file.c_str());
		while (getline(fin, line)) map_words(line);
		fin.close();
	}
	
	vector<string> Dictionary::split(string& s, const string&& delimiter, const bool&& grab_word) {
		vector<string> list;
		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != string::npos) {
			list.emplace_back(s.substr(0, pos));
			s.erase(0, pos + delimiter.length());
			if (grab_word) break;
		}
		list.emplace_back(s);
		return list;
	}

	void Dictionary::map_words(string& line) {
		string word{ split(line, "|", true)[0] };
		vector<string> definition = split(line, "|"), temp(2);
		Word word_info(definition.size());
		for (int i = 0; i < definition.size(); i++) {
			temp = split(definition[i], " -=>> ", true);
			if (temp.size() != 2) break;
			word_info.list.emplace_back(temp[0], temp[1]);
			definitions++;
		}
		mapped_words.insert({word, word_info});
	}
