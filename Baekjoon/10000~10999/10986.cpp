#include <iostream>

using namespace std;

int N, M;
long long rems[1001];

long long sum;
long long ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		sum += tmp;
		rems[sum % M]++;
	}

	for (int i = 0; i < 1001; i++) {
		ans += rems[i] * (rems[i] - 1) / 2;
	}
	ans += rems[0];

	cout << ans << "\n";

	return 0;
}