#include <iostream>
#include <map>

using namespace std;

map<string, string> schoolMap = {
	{ "NLCS", "North London Collegiate School" },
	{ "BHA", "Branksome Hall Asia" },
	{ "KIS", "Korea International School" },
	{ "SJA", "St. Johnsbury Academy" },
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	cout << schoolMap[str] << "\n";

	return 0;
}