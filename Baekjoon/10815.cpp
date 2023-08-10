#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	set<int> nums;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		nums.insert(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;

		nums.find(tmp) == nums.end() ? cout << "0 " : cout << "1 ";
	}
	cout << "\n";

	return 0;
}