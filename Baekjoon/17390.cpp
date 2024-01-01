#include <bits/stdc++.h>

using namespace std;

int get_answer(vector<int> &partial_sum, int l, int r)
{
	if (l == 1) {
		return partial_sum[r - 1];
	} else {
		return partial_sum[r - 1] - partial_sum[l - 2];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sequence_len;
	int question_count;
	vector<int> sequence;
	vector<int> sum_of_sequence;

	cin >> sequence_len >> question_count;

	for (int i = 0; i < sequence_len; i++) {
		int element;
		cin >> element;
		sequence.push_back(element);
	}
	sort(sequence.begin(), sequence.end());
	for (int i = 0; i < sequence_len; i++) {
		if (i == 0) {
			sum_of_sequence.push_back(sequence[i]);
		} else {
			sum_of_sequence.push_back(sum_of_sequence[i - 1] + sequence[i]);
		}
	}

	for (int i = 0; i < question_count; i++) {
		int l, r;
		cin >> l >> r;
		cout << get_answer(sum_of_sequence, l, r) << "\n";
	}

	return 0;
}