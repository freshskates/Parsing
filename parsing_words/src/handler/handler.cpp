#include "handler.h"
#include <algorithm>
//remove duplicates
void Handler::removedup(vector<Definition>& definitions) {
	definitions.erase(unique(definitions.begin(), definitions.end(), [](const Definition& a, const Definition& b) -> bool { return a.meaning == b.meaning; }), definitions.end());
}

//filter part of speeches
void Handler::filter(vector<Definition>& definitions, const string& pos) {
	definitions.erase(remove_if(definitions.begin(), definitions.end(), [&pos](const Definition& a) -> bool { return a.POS != pos; }), definitions.end());
}

//reverse vector
void Handler::reverse_list(vector<Definition>& definitions) {
	reverse(definitions.begin(), definitions.end());
}

//sort vector lambda
void Handler::sort_list(vector<Definition>& definitions) {
	sort(definitions.begin(), definitions.end(), [](const Definition& a, const Definition& b) -> bool {return (a.POS + a.meaning) < (b.POS + b.meaning); });
}

