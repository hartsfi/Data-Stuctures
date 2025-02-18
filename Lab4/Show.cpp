#include "Show.h"

using namespace std;

//Constructor initialization
Show::Show() : title(), description() {}

Show::Show(string title, string description) : title(title), description(description) {}

//Base Details Fucntion - Prints the title and description of the Show
void Show::Details() const {

	cout << "Title: " << title
		<< endl << "Description: " << description << endl;
	
}
