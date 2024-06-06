#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
vector<char> operators;
vector<bool> visitFlags;

vector<string> answers;

bool Check(int n1, int n2, char op)
{
	if (op == '<') {
		return n1 < n2;
	} else if (op == '>') {
		return n1 > n2;
	}

	return true;
}

void Trace(int index = 0, string num = "")
{
	if (index == k + 1) {
		answers.push_back(num);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visitFlags[i])
			continue;

		if (index == 0 || Check(num[index - 1] - '0', i, operators[index - 1])) {
			visitFlags[i] = true;
			Trace(index + 1, num + to_string(i));
			visitFlags[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k;
	operators = vector<char>(k);
	visitFlags = vector<bool>(10, false);

	for (int i = 0; i < k; i++) {
		cin >> operators[i];
	}

	Trace();
	sort(answers.begin(), answers.end(), less<string>());

	cout << answers[answers.size() - 1] << "\n";
	cout << answers[0] << "\n";

	return 0;
}