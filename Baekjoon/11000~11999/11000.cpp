#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Class
{
	int S;
	int T;

	bool operator<(const Class &c) const
	{
		if (S != c.S) {
			return S < c.S;
		}

		return T < c.T;
	}
};

int N;
vector<Class> classes;

int GetClassroomCount()
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		pq.push(classes[i].T);
		if (pq.top() <= classes[i].S) {
			pq.pop();
		}
	}

	return pq.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	classes = vector<Class>(N);

	for (int i = 0; i < N; i++) {
		cin >> classes[i].S >> classes[i].T;
	}
	sort(classes.begin(), classes.end(), less<Class>());

	cout << GetClassroomCount() << "\n";

	return 0;
}