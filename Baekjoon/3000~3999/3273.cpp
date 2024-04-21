/**
 * 3273 백준 두 수의 합
 *
 * 수열을 입력받고, 수열의 두 원소를 선택해서
 * 특정 수가 되는 쌍이 몇 개인지 구하는 문제이다.
 *
 * 먼저 배열을 정렬하고, 투 포인터 알고리즘을 이용해
 * 만족하는 쌍의 개수를 구하면 된다.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arrLen;
vector<int> arr;
int target;

int GetCountOfPair()
{
	int begin = 0;
	int end = arrLen - 1;
	int curr = 0;
	int count = 0;

	while (begin < end)
	{
		curr = arr[begin] + arr[end];

		if (curr == target)
		{
			count++;
			begin++;
		}
		else if (curr < target)
		{
			begin++;
		}
		else if (curr > target)
		{
			end--;
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> arrLen;
	for (int i = 0; i < arrLen; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	cin >> target;

	sort(arr.begin(), arr.end(), less<int>());

	cout << GetCountOfPair() << "\n";

	return 0;
}