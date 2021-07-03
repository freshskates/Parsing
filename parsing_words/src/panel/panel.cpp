#include "panel.h"
#include "../handler/handler.h"
#include <algorithm>

    /**
     * Start will start a loop awaiting users input
     * Part of speech only 2nd parameter
     * Distinct up to 3rd parameter
     * Reverse up to 4th parameter
     * @apiNote Users input should consist of {Word} {{Part of Speech}} {Distinct} {Reverse}
     * !q for graceful exit
     * !help for help
     */
	void Panel::run() {
		status(info);
		while (true) {
			status(prompt);
			string line;
			getline(cin, line);
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			vector<string> user_input = Dictionary::split(line, " ");
			
			if (line.size() == 0) {
				status(help);
				continue;
			}
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

	/**
	 * Option will validate the options other than the word
	 * valid options consist of {Part of Speech}, {Distinct}, {Reverse}
	 *
	 * @apiNote If option not found, it will call nofFound method
	 */
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

	/**
     * Print out word and corresponding info
     */
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

