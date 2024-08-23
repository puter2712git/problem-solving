#include <iostream>

using namespace std;

int scores[50] = {};
int targetScore;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 50; i++) {
		cin >> scores[i];
	}
	cin >> targetScore;

	int rank = 1;
	for (int i = 0; i < 50; i++) {
		if (targetScore < scores[i])
			rank++;
	}

	if (rank >= 1 && rank <= 5)
		cout << "A+\n";
	else if (rank >= 1 && rank <= 15)
		cout << "A0\n";
	else if (rank >= 16 && rank <= 30)
		cout << "B+\n";
	else if (rank >= 31 && rank <= 35)
		cout << "B0\n";
	else if (rank >= 36 && rank <= 45)
		cout << "C+";
	else if (rank >= 46 && rank <= 48)
		cout << "C0\n";
	else
		cout << "F\n";

	return 0;
}