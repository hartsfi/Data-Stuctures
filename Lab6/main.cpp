#include "Stack.h"
#include "StackExceptions.h"
#include <iostream>

using namespace std;

int main() {

	Stack<int> my_stack(10);

	int a = 12, b = 22, c = 2;

	my_stack.push(new int(10));

	cout << "Top: " << *(my_stack.top()) << endl;

	my_stack.empty();

	return 0;
}
