#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int studyTime = 0;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		studyTime += tmp;
	}
	studyTime += 8 * (N - 1);

	cout << studyTime / 24 << " " << studyTime % 24 << "\n";

	return 0;
}