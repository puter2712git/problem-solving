#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<int> operators(4);

int maxValue = INT32_MIN;
int minValue = INT32_MAX;

void find_values(int depth = 0, int value = 0)
{
	if (depth == N) {
		maxValue = max(maxValue, value);
		minValue = min(minValue, value);
		return;
	}

	if (depth == 0) {
		find_values(depth + 1, A[0]);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] == 0) continue;

		operators[i]--;

		switch (i) {
		case 0:
			find_values(depth + 1, value + A[depth]);
			break;

		case 1:
			find_values(depth + 1, value - A[depth]);
			break;

		case 2:
			find_values(depth + 1, value * A[depth]);
			break;

		case 3:
			find_values(depth + 1, value / A[depth]);
			break;
		}

		operators[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	find_values();

	cout << maxValue << "\n";
	cout << minValue << "\n";

	return 0;
}