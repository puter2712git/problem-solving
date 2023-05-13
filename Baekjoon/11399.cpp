#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int take_times[1000];

	int answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> take_times[i];
	}

	sort(take_times, take_times + n);

	int tmp = 0;
	
	for (int i = 0; i < n; i++) {
		tmp += take_times[i];
		answer += tmp;
	}

	cout << answer << '\n';

	return 0;
}