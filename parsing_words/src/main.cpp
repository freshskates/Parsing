#include "panel/panel.h"
/**
 * @author Robert Cacho Ruiz
 *
 * Main class only uses the Panel Class,
 * Panel Class has access to Data and Handles it accordingly
 * src/data/sfsu.txt
 */
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	string file = "src/data/sfsu.txt";
	Dictionary storage(file);
	storage.read();
	Panel panel(storage);
	panel.run();
}
