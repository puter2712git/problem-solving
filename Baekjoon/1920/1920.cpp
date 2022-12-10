#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(int target, vector<long long int> &array) {
	int start = 0;
	int end = array.size() - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (target == array[mid]) {
			return true;
		}
		else if (target < array[mid]) {
			end = mid - 1;
		}
		else if (target > array[mid]) {
			start = mid + 1;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n_count, m_count;
	bool is_included = false;

	cin >> n_count;
	vector<long long int> n_array(n_count);
	for (int i = 0; i < n_count; i++) {
		cin >> n_array[i];
	}

	sort(n_array.begin(), n_array.end());

	cin >> m_count;

	for (int i = 0; i < m_count; i++) {
		int m;
		cin >> m;
		if (binary_search(m, n_array)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}