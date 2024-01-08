#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int array_size;
	vector<int> array;

	int answer;

	cin >> array_size;
	array = vector<int>(array_size, 0);
	for (int i = 0; i < array_size; i++) {
		int index;
		cin >> index;
		array[index]++;

		if (array[index] == 2) {
			answer = index;
		}
	}

	cout << answer << "\n";
	return 0;
}