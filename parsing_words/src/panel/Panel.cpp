#include "Panel.h"
#include "../handler/handler.h"


	void Panel::run() {
		status(info);
		while (true) {
			string line;
			getline(cin, line);
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			vector<string> user_input = Dictionary::split(line, " ");
			if (!user_input.size() || user_input.size() > 4 || user_input[0] == "!q") break;
			if (temp.mapped_words.count(user_input[0])) {
				this->display = temp.mapped_words.at(user_input[0]).list; 
				for (int i = 1; i < user_input.size(); i++) option(user_input[i]);
				print();
			}
		}
	}

	void Panel::option(const string& check) {
		if (check == options[0]) Handler::removedup(this->display);
		else if (check == options[1]) Handler::reverse_list(this->display);
		for (int i = 2; i < options.size(); i++) if (check == options[i]) Handler::filter(this->display, options[i]);
	}

	void Panel::print() {
		cout << endl;
		for_each(display.begin(), display.end(), [](const Definition& a) -> void { cout << "[" << a.POS << "] " << a.meaning << endl; });
		cout << endl; 
	}

