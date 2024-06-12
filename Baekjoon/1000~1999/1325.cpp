#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Computer
{
	vector<int> trustedIndices;
	bool isHacked;
	int hackCount;
};

int N, M;
vector<Computer> computers;
int maxHackCount;

void Hack()
{
	for (int i = 1; i <= N; i++) {
		for (auto &computer : computers) {
			computer.isHacked = false;
		}

		stack<int> s;
		int hackCount = 0;

		s.push(i);
		computers[i].isHacked = true;

		while (!s.empty()) {
			int currIndex = s.top();
			s.pop();
			hackCount++;

			Computer currComputer = computers[currIndex];
			for (const auto &index : currComputer.trustedIndices) {
				if (computers[index].isHacked)
					continue;

				computers[index].isHacked = true;
				s.push(index);
			}
		}

		maxHackCount = max(hackCount, maxHackCount);
		computers[i].hackCount = hackCount;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	computers = vector<Computer>(N + 1, Computer{ vector<int>(0), false, 0 });
	while (M--) {
		int A, B;
		cin >> A >> B;
		computers[B].trustedIndices.push_back(A);
	}

	Hack();

	for (int i = 1; i <= N; i++) {
		if (computers[i].hackCount == maxHackCount) {
			cout << i << " ";
		}
	}
	cout << "\n";

	return 0;
}