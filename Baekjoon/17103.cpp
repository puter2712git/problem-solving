#include <iostream>
#include <vector>

using namespace std;

vector<bool> make_is_prime_set(int range)
{
	vector<bool> ret = vector<bool>(range, true);

	for (int i = 2; i < range; i++) {
		if (!ret[i]) continue;

		for (int j = i * 2; j < range; j += i) {
			ret[j] = false;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	int N;
	vector<bool> is_prime_set = make_is_prime_set(1000001);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int count = 0;

		for (int j = 2; j <= N / 2; j++) {
			if (is_prime_set[j] && is_prime_set[N - j]) {
				count++;
			}
		}

		cout << count << "\n";
	}

	return 0;
}