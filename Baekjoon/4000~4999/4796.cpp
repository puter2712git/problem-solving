#include <iostream>

using namespace std;

int L, P, V;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int caseIndex = 1;
	int usableDays = 0;

	while (true) {
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) {
			break;
		}

		usableDays = (V / P) * L;
		usableDays += min(V % P, L);

		cout << "Case " << caseIndex << ": " << usableDays << "\n";
		caseIndex++;
	}

	return 0;
}