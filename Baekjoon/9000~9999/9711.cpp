#include <iostream>
#include <vector>

using namespace std;

int T;
int P, Q;
vector<long long> nums;

void Fill()
{
	nums.clear();
	nums = vector<long long>(P + 1);

	nums[0] = 0;
	nums[1] = 1 % Q;

	for (int i = 2; i <= P; i++) {
		nums[i] = (nums[i - 2] + nums[i - 1]) % Q;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> P >> Q;
		Fill();

		cout << "Case #" << i << ": " << nums[P] << "\n";
	}

	return 0;
}