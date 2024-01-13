#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> A, B;
	int M;
	vector<int> C;

	queue<int> q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		B.push_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		C.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		if (A[N - 1 - i] == 1) continue;
		q.push(B[N - 1 - i]);
	}

	for (int i = 0; i < M; i++) {
		q.push(C[i]);
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";

	return 0;
}