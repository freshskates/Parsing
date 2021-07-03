#include "panel.h"

/**
 * Status is used to print out error, help, info and prompt messages to user
 * @param flag Integer that will be bit masked to see what options were selected
 * @apiNote notFound:  1     0x00000001
 * @apiNote Help:      2     0x00000010
 * @apiNote Info:      4     0x00000100
 * @apiNote Prompt:    8     0x00001000
 * @apiNote exit:     16     0x00010000
 * Bitmask: Popular approach in many big libraries to increase flexibility
 * Example: To print Help then a prompt, you need to 'or' the values
 * status(2 | 8) or status(help | prompt), both will print help menu then prompt users input
 */
void Panel::status(int flag) {
	
    if (flag & notFound) {
        cout << "\t|\n\t<Not found> To be considered for the next release. Thank you.\n\t|\n";
    }

    if (flag & help) {
        cout << "\t|\n\tPARAMETER HOW-T0, please enter:\n";
        cout << "\t1. A search key -then 2. An optional part of speech -then\n";
        cout << "\t3. An optional 'distinct' -then 4. An optional 'reverse'\n\t|\n";
    }

    if (flag & info) {
        cout << "! Loading data...\n";
        cout << "! Loading completed...\n";
        cout << "===== DICTIONARY 340 C++ =====\n";
        cout << "----- Keywords: " << this->temp.mapped_words.size() << "\n";
        cout << "----- Definitions: " << this->temp.definitions << "\n";
    }

    if (flag & prompt) {
        cout << "Search [" <<  ++this->count << "]: ";
    }

    if (flag & quit) {
        cout << "-----THANK YOU-----\n";
    }

}

/**
 * notFound is used when user input was not recognized
 * Prints out error message to user
 * @param index will be the n_th phrase that is considered as the user's input
 * @param option users input that was not recognized
 */
void Panel::error(int index, string option) {
    vector<string> opts = { "a part of speech", "'distinct'", "'reverse'" };
    string suffix[] = { "nd", "rd", "th" };
    string param = to_string(index + 1) + suffix[index - 1];
    
    cout << "\t|\n";
    
    for (int i = index - 1; i < opts.size(); i++)
        cout << "\t<The entered " << param << " parameter '" << option << "' is NOT " << opts[i] << ".>\n" ;
    cout << "\t<The entered " << param << " parameter '" << option << "' was disregarded.>\n";

    string joinedString; 
    for (int i = index - 1; i < opts.size(); i++) {
        if (i == opts.size() - 1)
            joinedString.append(opts[i]);
        else
            joinedString.append(opts[i].append(" or "));
    }

    cout << "\t<The " << param << " parameter should be " << joinedString <<  ".>\n\t|\n";
}