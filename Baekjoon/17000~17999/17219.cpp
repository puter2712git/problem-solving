#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int siteLength;
    int findSiteLength;
    map<string, string> passwordMap;

    cin >> siteLength >> findSiteLength;
    for (int i = 0; i < siteLength; i++) {
        string site;
        string password;
        cin >> site >> password;
        passwordMap.insert({ site, password });
    }

    for (int i = 0; i < findSiteLength; i++) {
        string site;
        cin >> site;
        cout << passwordMap[site] << "\n";
    }

    return 0;
}