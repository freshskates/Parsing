#include "Header.h"
#include "Dictionary.h"
#include "Panel.h"

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	string file = "sfsu.txt";
	Dictionary storage(file);
	storage.read();
	Panel panel(storage);
	panel.start();
}
