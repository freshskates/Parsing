#include "Panel.h"

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
        cout << "===== DICTIONARY 340 JAVA =====\n";
        cout << "----- Keywords: " << this->temp.mapped_words.size() << "\n";
        cout << "----- Definitions: " << this->temp.definitions << "\n";
    }

    if (flag & prompt) {
        cout << "Search [ " <<  ++this->count << "]: ";
    }

    if (flag & quit) {
        cout << "-----THANK YOU-----";
    }

}