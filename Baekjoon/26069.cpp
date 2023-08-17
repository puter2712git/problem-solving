#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	set<string> dance;

	dance.insert("ChongChong");

	cin >> N;
	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;

		if (dance.find(a) != dance.end()) {
			dance.insert(b);
		}

		if (dance.find(b) != dance.end()) {
			dance.insert(a);
		}
	}

	cout << dance.size() << "\n";

	return 0;
}