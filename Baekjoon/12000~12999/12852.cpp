#include <iostream>
#include <vector>

using namespace std;

struct Element
{
	int count;
	vector<int> nums;
};

int N;
vector<Element> elements;

void Fill()
{
	elements[1].count = 0;
	elements[1].nums.push_back(1);

	elements[2].count = 1;
	elements[2].nums.push_back(1);
	elements[2].nums.push_back(2);

	elements[3].count = 1;
	elements[3].nums.push_back(1);
	elements[3].nums.push_back(3);

	for (int i = 4; i <= N; i++) {
		int count = 0;
		int type = -1;

		// 1 빼기
		count = elements[i - 1].count + 1;
		type = 3;

		// 3 나누기
		if (i % 3 == 0) {
			if (elements[i / 3].count + 1 < count) {
				count = elements[i / 3].count + 1;
				type = 1;
			}
		}

		// 2 나누기
		if (i % 2 == 0) {
			if (elements[i / 2].count + 1 < count) {
				count = elements[i / 2].count + 1;
				type = 2;
			}
		}

		elements[i].count = count;

		switch (type) {
		case 1:
			elements[i].nums = elements[i / 3].nums;
			break;
		case 2:
			elements[i].nums = elements[i / 2].nums;
			break;
		case 3:
			elements[i].nums = elements[i - 1].nums;
			break;
		}
		elements[i].nums.push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	elements = vector<Element>(N + 1 > 4 ? N + 1 : 4, Element{ 0, vector<int>() });

	Fill();

	cout << elements[N].count << "\n";
	for (int i = elements[N].nums.size() - 1; i >= 0; i--) {
		cout << elements[N].nums[i] << " ";
	}
	cout << "\n";

	return 0;
}