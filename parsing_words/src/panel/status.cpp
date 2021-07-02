#include "panel.h"

/**
 * 
 *  
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
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