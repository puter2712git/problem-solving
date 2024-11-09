#include <iostream>
#include <map>

using namespace std;

int N;
const map<string, string> seminarMap = {
    {"Algorithm", "204"},
    {"DataAnalysis", "207"},
    {"ArtificialIntelligence", "302"},
    {"CyberSecurity", "B101"},
    {"Network", "303"},
    {"Startup", "501"},
    {"TestStrategy", "105"}};

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N;
}

void Solve()
{
    string seminarName;

    for (int i = 0; i < N; i++)
    {
        cin >> seminarName;
        cout << seminarMap.at(seminarName) << "\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}