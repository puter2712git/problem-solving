#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeList;

void merge(vector<int> &arr, int p, int q, int r)
{
	int i = p;
	int j = q + 1;

	vector<int> tmp;

	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) {
			tmp.push_back(arr[i++]);
		} else {
			tmp.push_back(arr[j++]);
		}
	}
	while (i <= q) tmp.push_back(arr[i++]);
	while (j <= r) tmp.push_back(arr[j++]);

	i = p;
	int t = 0;

	while (i <= r) {
		mergeList.push_back(tmp[t]);
		arr[i++] = tmp[t++];
	}
}

void merge_sort(vector<int> &arr, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	vector<int> array;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int element;
		cin >> element;
		array.push_back(element);
	}

	merge_sort(array, 0, array.size() - 1);

	if (mergeList.size() < K) {
		cout << -1 << "\n";
	} else {
		cout << mergeList[K - 1] << "\n";
	}

	return 0;
}