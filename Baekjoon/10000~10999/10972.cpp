/**
 * 특정 순열이 주어졌을 때, 그 다음의 순열을 구하기
 *
 * 뒤에서부터 순회하며, 오름차순이 끊겼을 때의 인덱스를 구한다.
 * 다시 뒤에서부터 순회하며, 해당 인덱스의 값보다 큰 값과 swap한다.
 * 그 뒤, 인덱스 이후의 배열을 오름차순하여 정렬한다.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> sequence;

int FindIncreasingBreakPointFromEnd()
{
	for (int i = sequence.size() - 1; i > 0; i--) {
		if (sequence[i - 1] < sequence[i]) {
			return i - 1;
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		sequence.push_back(num);
	}

	int breakPoint = FindIncreasingBreakPointFromEnd();
	if (breakPoint == -1) {
		cout << -1 << "\n";
		return 0;
	}

	for (int i = sequence.size() - 1; i >= breakPoint; i--) {
		if (sequence[i] > sequence[breakPoint]) {
			swap(sequence[i], sequence[breakPoint]);
			break;
		}
	}

	sort(sequence.begin() + breakPoint + 1, sequence.end(), less<int>());

	for (int i = 0; i < n; i++) {
		cout << sequence[i] << " ";
	}
	cout << "\n";

	return 0;
}