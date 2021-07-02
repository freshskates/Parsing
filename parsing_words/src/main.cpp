#include "panel/panel.h"

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	string file = "src/data/sfsu.txt";
	Dictionary storage(file);
	storage.read();
	Panel panel(storage);
	panel.run();
}
