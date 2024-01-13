#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> line;

	stack<int> curr;
	stack<int> another;
	int currNum = 1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		line.push_back(n);
	}

	for (int i = 0; i < N; i++) {
		curr.push(line[N - 1 - i]);
	}

	while (!curr.empty() || !another.empty()) {
		if (!curr.empty() && curr.top() == currNum) {
			curr.pop();
			currNum++;
			continue;
		}
		if (!another.empty() && another.top() == currNum) {
			another.pop();
			currNum++;
			continue;
		}

		if (curr.empty()) {
			cout << "Sad" << '\n';
			break;
		}

		another.push(curr.top());
		curr.pop();
	}

	if (curr.empty() && another.empty()) {
		cout << "Nice" << '\n';
	}

	return 0;
}