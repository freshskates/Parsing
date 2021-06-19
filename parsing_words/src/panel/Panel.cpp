#include "Panel.h"
#include "../handler/handler.h"
#include <algorithm>

	void Panel::run() {
		status(info);
		while (true) {
			status(prompt);
			string line;
			getline(cin, line);
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			vector<string> user_input = Dictionary::split(line, " ");
			if (user_input[0] == options[0]) break;

			if (!user_input.size() || user_input.size() > 4 || user_input[0] == options[1]) {
				status(help);
				continue;
			}
			
			if (!temp.mapped_words.count(user_input[0])) {
				status(notFound | help);
				continue;
			}

			this->display = temp.mapped_words.at(user_input[0]).list, Handler::sort_list(this->display); 
			for (int i = 1; i < user_input.size(); i++) option(user_input[i], i);
			print(user_input[0]);
			
		}
		status(quit);
	}

	void Panel::option(const string& check, int& index) {
		for (int i = 0; i < partOfSpeeches.size() && index == 1; i++)
			if (check == partOfSpeeches[i]) {
				Handler::filter(this->display, partOfSpeeches[i]);
				return;
			}
		if (check == options[2] && index <= 2) {
			Handler::removedup(this->display);
			return;
		}
		if (check == options[3]) {
			Handler::reverse_list(this->display);
			return;
		}
		error(index, check);
	}

	void Panel::print(string& word) {
		if (!this->display.size()) {
			status(notFound | help);
			return;
		}
		cout << "\t|\n";
		word[0] = toupper(word[0]);
		for_each(display.begin(), display.end(), [&word](const Definition& a) -> void { cout << "\t" << word << " [" << a.POS << "] " << a.meaning << endl; });
		cout << "\t|\n";
	}

