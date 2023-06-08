#include <iostream>
#include <map>

using namespace std;

int get_sub_element_count(map<int, int> &target, map<int, int> &subtracted)
{
	int dup_count = 0;

	for (auto iter = subtracted.begin(); iter != subtracted.end(); iter++) {
		if (target.find(iter->first) != target.end()) {
			dup_count++;
		}
	}

	return target.size() - dup_count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	map<int, int> A, B;
	int A_count, B_count;

	cin >> A_count >> B_count;
	for (int i = 0; i < A_count; i++) {
		int element;
		cin >> element;
		A.insert({ element, 0 });
	}
	for (int i = 0; i < B_count; i++) {
		int element;
		cin >> element;
		B.insert({ element, 0 });
	}

	cout << get_sub_element_count(A, B) + get_sub_element_count(B, A) << "\n";

	return 0;
}