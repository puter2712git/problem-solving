#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> fruits;
vector<int> fruitCounts;

int GetMaxFruitCount()
{
	int ret = 0;

	int begin = 0;
	int end = 1;

	fruitCounts[fruits[0]]++;
	int kinds = 1;

	while (true) {
		if (kinds <= 2) {
			ret = max(ret, end - begin);
			end++;

			if (end <= N) {
				fruitCounts[fruits[end - 1]]++;
				if (fruitCounts[fruits[end - 1]] == 1) {
					kinds++;
				}
			} else {
				break;
			}
		} else if (kinds > 2) {
			begin++;
			fruitCounts[fruits[begin - 1]]--;
			if (fruitCounts[fruits[begin - 1]] == 0) {
				kinds--;
			}
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	fruits = vector<int>(N);
	fruitCounts = vector<int>(10, 0);
	for (int i = 0; i < N; i++) {
		cin >> fruits[i];
	}

	cout << GetMaxFruitCount() << "\n";

	return 0;
}