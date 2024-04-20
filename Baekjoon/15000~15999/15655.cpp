/**
 * 백준 15655 N과 M (6)
 *
 * 1. 입력을 받아 오름차순으로 정렬된 배열을 만든다.
 * 2. 백트래킹을 사용하는데, 시작 인덱스를 지정하여 배열을 탐색하여
 * 오름차순으로 생성되도록 한다.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int numLen;
int seqLen;
vector<int> nums;
vector<int> seq;

void PrintSequences(int beginIndex, int currLen)
{
	if (currLen == seqLen)
	{
		for (int i = 0; i < seqLen; i++)
		{
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = beginIndex; i < numLen; i++)
	{
		seq[currLen] = nums[i];
		PrintSequences(i + 1, currLen + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> numLen >> seqLen;
	nums = vector<int>(numLen);
	seq = vector<int>(seqLen);

	for (int i = 0; i < numLen; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), less<int>());

	PrintSequences(0, 0);

	return 0;
}