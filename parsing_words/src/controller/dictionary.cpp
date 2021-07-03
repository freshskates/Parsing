#include "dictionary.h"
#include <fstream>

/*
! Opening data file... C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt
<!>ERROR<!> ===> File could not be opened.
<!>ERROR<!> ===> Provided file path: C:\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt
<!>Enter the CORRECT data file path: ./Data.CS.SFSU.txt
src/data/sfsu.txt
*/

	void Dictionary::read() {
		string line;
		ifstream fin;
		bool valid = false; 
		do {
		cout << "! Opening data file... " << this->file << endl; 
		fin.open(this->file.c_str());
		if (!fin.is_open()) {
			cout << "<!>ERROR<!> == = > File could not be opened." << endl; 
			cout << "<!>ERROR<!> == = > Provided file path : " << this->file << endl; 
			cout << "<!>Enter the CORRECT data file path : "; 
			cin >> this->file; 
		}
		else {
			valid = true; 
		}
		} while (!valid);
		while (getline(fin, line)) map_words(line);
		fin.close();
	}
	
	vector<string> Dictionary::split(string& s, const string&& delimiter, const bool&& grab_word) {
		vector<string> list;
		size_t pos{};
		while ((pos = s.find(delimiter)) != string::npos) {
			list.emplace_back(s.substr(0, pos));
			s.erase(0, pos + delimiter.length());
			if (grab_word) break;
		}
		if(s.size()) list.emplace_back(s);
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
