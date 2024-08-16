#include <iostream>

using namespace std;

int N, U, L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> U >> L;

	bool hasSatisfiedSolvedCount = false;
	bool hasSatisfiedMapleLevel = false;

	if (N >= 1000)
		hasSatisfiedSolvedCount = true;
	if (U >= 8000 || L >= 260)
		hasSatisfiedMapleLevel = true;

	if (hasSatisfiedSolvedCount && hasSatisfiedMapleLevel) {
		cout << "Very Good\n";
	} else if (hasSatisfiedSolvedCount) {
		cout << "Good\n";
	} else {
		cout << "Bad\n";
	}

	return 0;
}