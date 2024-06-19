#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> A, B;

void Swap3X3(vector<vector<char>> &mat, int row, int column)
{
	for (int i = row; i < row + 3; i++) {
		for (int j = column; j < column + 3; j++) {
			mat[i][j] = mat[i][j] == '0' ? '1' : '0';
		}
	}
}

bool IsSame()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	A = vector<vector<char>>(N, vector<char>(M));
	B = vector<vector<char>>(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}

	int swapCount = 0;

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				swapCount++;
				Swap3X3(A, i, j);
			}
		}
	}

	if (IsSame()) {
		cout << swapCount << "\n";
	} else {
		cout << -1 << "\n";
	}

	return 0;
}