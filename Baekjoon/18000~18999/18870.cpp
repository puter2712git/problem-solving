#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int input_count;
	vector<int> nums;
	vector<int> tmp;

	map<int, int> compressed;

	cin >> input_count;
	for (int i = 0; i < input_count; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
		tmp.push_back(num);
	}

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		compressed.insert({ nums[i], i });
	}

	for (int i = 0; i < tmp.size(); i++) {
		cout << compressed[tmp[i]] << " ";
	}
	cout << "\n";

	return 0;
}