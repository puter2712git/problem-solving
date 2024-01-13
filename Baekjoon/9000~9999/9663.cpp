#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

int answer;
vector<int> queen_columns(15);

bool promising(int depth, int column)
{
	for (int i = 0; i < depth; i++) {
		if (column == queen_columns[i]) return false;
		if (abs(depth - i) == abs(column - queen_columns[i])) return false;
	}

	return true;
}

void find_nqueen_ways(int depth)
{
	if (depth == N) {
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!promising(depth, i)) continue;

		queen_columns[depth] = i;
		find_nqueen_ways(depth + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	find_nqueen_ways(0);
	cout << answer << "\n";

	return 0;
}