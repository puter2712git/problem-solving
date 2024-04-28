#include <iostream>
#include <set>
#include <string>

using namespace std;

int N;
set<int> numbers;

void FillUp()
{
	for (int i = 111; i <= 999; i++) {
		string curr = to_string(i);
		if (curr.find('0') != string::npos)
			continue;
		if (curr[0] == curr[1] || curr[0] == curr[2] || curr[1] == curr[2])
			continue;

		numbers.insert(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	FillUp();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		int strike;
		int ball;
		cin >> number >> strike >> ball;

		auto iter = numbers.begin();
		while (iter != numbers.end()) {
			int currIter = *iter;

			string curr = to_string(currIter);
			string compare = to_string(number);

			int strikeCount = 0;
			int ballCount = 0;

			for (int j = 0; j < 3; j++) {
				if (curr[j] == compare[j]) {
					strikeCount++;
				} else if (compare.find(curr[j]) != string::npos) {
					ballCount++;
				}
			}

			iter++;

			if (strikeCount != strike || ballCount != ball) {
				numbers.erase(currIter);
			}
		}
	}

	cout << numbers.size() << "\n";

	return 0;
}