#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Stack {
private:
	int _elements[1000000];
	int _top;

public:
	Stack()
	{
		_top = -1;
	}
	~Stack() {}

	void Push(int item)
	{
		_elements[++_top] = item;
	}
	void Pop()
	{
		if (_top == -1) {
			cout << -1 << "\n";
		}
		else {
			cout << _elements[_top--] << "\n";
		}
	}
	void PrintCountOfElement()
	{
		cout << _top + 1 << "\n";
	}
	void PrintIsEmpty()
	{
		if (_top == -1) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	void PrintTopElement()
	{
		if (_top == -1) {
			cout << -1 << "\n";
		}
		else {
			cout << _elements[_top] << "\n";
		}
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	Stack stack;

	istringstream iss;
	string input;
	string command;

	cin >> N;
	cin.ignore();
	
	for (int i = 0; i < N; i++) {
		getline(cin, input, '\n');

		iss.clear();
		iss.str(input);
		iss >> command;

		if (command == "1") {
			int item;
			iss >> item;
			stack.Push(item);
		}
		else if (command == "2") {
			stack.Pop();
		}
		else if (command == "3") {
			stack.PrintCountOfElement();
		}
		else if (command == "4") {
			stack.PrintIsEmpty();
		}
		else if (command == "5") {
			stack.PrintTopElement();
		}
	}

	return 0;
}