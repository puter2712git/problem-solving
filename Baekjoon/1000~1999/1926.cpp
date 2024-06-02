#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Pixel
{
	int data;
	bool isVisited;
};

const pair<int, int> directions[4] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

int n, m;
vector<vector<Pixel>> paper;

vector<int> GetPictures()
{
	vector<int> ret;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j].data == 0 || paper[i][j].isVisited)
				continue;

			stack<pair<int, int>> s;
			s.push({ i, j });
			paper[i][j].isVisited = true;

			int picSize = 1;

			while (!s.empty()) {
				pair<int, int> curr = s.top();
				s.pop();

				for (int k = 0; k < 4; k++) {
					pair<int, int> currDir = directions[k];
					int row = curr.first + currDir.first;
					int column = curr.second + currDir.second;

					if (row < 0 || row >= n || column < 0 || column >= m)
						continue;
					if (paper[row][column].data == 0 || paper[row][column].isVisited)
						continue;

					s.push({ row, column });
					paper[row][column].isVisited = true;
					picSize++;
				}
			}

			ret.push_back(picSize);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	paper = vector<vector<Pixel>>(n, vector<Pixel>(m, Pixel{ -1, false }));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j].data;
		}
	}

	vector<int> pictures = GetPictures();
	sort(pictures.begin(), pictures.end(), greater<int>());

	cout << pictures.size() << "\n";
	if (pictures.size() == 0) {
		cout << 0 << "\n";
	} else {
		cout << pictures[0] << "\n";
	}

	return 0;
}