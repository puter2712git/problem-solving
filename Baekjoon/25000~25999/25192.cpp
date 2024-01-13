#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	map<string, int> chats;

	int count = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string nickname;
		cin >> nickname;

		if (nickname == "ENTER") {
			chats.clear();
			continue;
		}
		if (chats.find(nickname) != chats.end()) continue;

		chats.insert({ nickname, 0 });
		count++;
	}

	cout << count << "\n";

	return 0;
}