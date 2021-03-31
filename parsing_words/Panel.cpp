#include "Panel.h"

	void Panel::help() {
		cout << "Keywords: " << temp.mapped_words.size() << "\nDefinitions: " << temp.definitions << endl;
		cout << "Dictionary Menu" << endl;
		cout << "<word> <pos> <distinct> <reverse>" << endl; 
		cout << "Enter Statement: ";
	}

	void Panel::start() {
		while (true) {
			help();
			string line;
			getline(cin, line);
			vector<string> user_input = Dictionary::split(line, " ");
			if (!user_input.size() || user_input.size() > 4 || user_input[0] == "!q") break;
			if (temp.mapped_words.count(user_input[0])) {
				this->display = temp.mapped_words.at(user_input[0]).list, sort_list();
				for (int i = 1; i < user_input.size(); i++) option(user_input[i]);
				print();
			}
		}
	}

	void Panel::option(const string& check) {
		if (check == options[0]) removedup();
		else if (check == options[1]) reverse_list();
		for (int i = 2; i < options.size(); i++) if (check == options[i]) filter(options[i]);
	}
	void Panel::print() {
		cout << endl;
		for_each(display.begin(), display.end(), [](Definition& a) -> void { cout << "[" << a.POS << "] " << a.meaning << endl; });
		cout << endl; 
	}
	void Panel::sort_list() {
		sort(display.begin(), display.end(), [](Definition& a, Definition& b) -> bool {return a.meaning < b.meaning; });
	}
	void Panel::removedup() {
		display.erase(unique(display.begin(), display.end(), [](Definition& a, Definition& b) -> bool { return a.meaning == b.meaning; }), display.end());
	}
	void Panel::filter(const string& pos) {
		display.erase(remove_if(display.begin(), display.end(), [&pos](Definition& a) -> bool { return a.POS != pos; }), display.end());
	}
	void Panel::reverse_list() {
		reverse(display.begin(), display.end());
	}
