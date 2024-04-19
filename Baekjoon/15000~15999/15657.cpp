#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int numLength;
int seqLength;
vector<int> nums;
vector<int> sequence;

void PrintSequences(int startIndex, int currLen)
{
	if (currLen == seqLength)
	{
		for (int i = 0; i < seqLength; i++)
		{
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = startIndex; i < numLength; i++)
	{
		sequence[currLen] = nums[i];
		PrintSequences(i, currLen + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> numLength >> seqLength;
	for (int i = 0; i < numLength; i++)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end(), less<int>());
	sequence = vector<int>(seqLength);

	PrintSequences(0, 0);

	return 0;
}