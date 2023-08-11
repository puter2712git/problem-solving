#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Queue {
private:
	int _front;
	int _rear;
	int _elements[2000000];

public:
	Queue()
	{
		_front = -1;
		_rear = -1;
	}
	void Push(int item)
	{
		_elements[++_rear] = item;
	}
	void Pop()
	{
		if (_front == _rear) {
			cout << -1 << '\n';
			return;
		}

		cout << _elements[++_front] << '\n';
	}
	void PrintSize()
	{
		cout << _rear - _front << '\n';
	}
	void PrintIsEmpty()
	{
		if (_front == _rear) {
			cout << 1 << '\n';
			return;
		}

		cout << 0 << '\n';
	}
	void PrintFrontElement()
	{
		if (_front == _rear) {
			cout << -1 << '\n';
			return;
		}

		cout << _elements[_front + 1] << '\n';
	}
	void PrintRearElement()
	{
		if (_front == _rear) {
			cout << -1 << '\n';
			return;
		}

		cout << _elements[_rear] << '\n';
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	Queue *queue = new Queue;

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

		if (command == "push") {
			int arg;
			iss >> arg;
			queue->Push(arg);
		}
		else if (command == "pop") {
			queue->Pop();
		}
		else if (command == "size") {
			queue->PrintSize();
		}
		else if (command == "empty") {
			queue->PrintIsEmpty();
		}
		else if (command == "front") {
			queue->PrintFrontElement();
		}
		else if (command == "back") {
			queue->PrintRearElement();
		}
	}

	delete queue;

	return 0;
}