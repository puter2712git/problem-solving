#include <iostream>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	deque<int> d;

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
			d.push_front(item);
		}
		else if (command == "2") {
			int item;
			iss >> item;
			d.push_back(item);
		}
		else if (command == "3") {
			if (d.empty()) {
				cout << -1 << '\n';
				continue;
			}

			cout << d.front() << '\n';
			d.pop_front();
		}
		else if (command == "4") {
			if (d.empty()) {
				cout << -1 << '\n';
				continue;
			}

			cout << d.back() << '\n';
			d.pop_back();
		}
		else if (command == "5") {
			cout << d.size() << '\n';
		}
		else if (command == "6") {
			cout << (d.empty() ? 1 : 0) << '\n';
		}
		else if (command == "7") {
			cout << (d.empty() ? -1 : d.front()) << '\n';
		}
		else if (command == "8") {
			cout << (d.empty() ? -1 : d.back()) << '\n';
		}
	}

	return 0;
}