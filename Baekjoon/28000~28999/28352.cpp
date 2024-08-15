#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int week = 6;
	for (int i = 11; i <= N; i++) {
		week *= i;
	}

	cout << week << "\n";

	return 0;
}