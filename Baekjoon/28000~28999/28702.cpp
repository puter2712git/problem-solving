#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> sequence;

bool IsNumber(string &target)
{
	size_t len = target.length();
	for (int i = 0; i < len; i++) {
		if (!isdigit(target[i])) {
			return false;
		}
	}

	return true;
}

void PrintBuzz(int num)
{
	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz\n";
	} else if (num % 3 == 0) {
		cout << "Fizz\n";
	} else if (num % 5 == 0) {
		cout << "Buzz\n";
	} else {
		cout << num << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int targetNumber = 0;

	sequence = vector<string>(3);
	for (int i = 0; i < 3; i++) {
		cin >> sequence[i];

		if (IsNumber(sequence[i])) {
			targetNumber = stoi(sequence[i]) + 3 - i;
		}
	}

	PrintBuzz(targetNumber);

	return 0;
}