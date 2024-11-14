#include <iostream>
#include <string>

using namespace std;

string S;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    getline(cin, S);
}

void Solve()
{
    int len = S.length();

    if (len > 1 && S[0] == '\"' && S[len - 1] == '\"' && S != "\"\"")
    {
        cout << S.substr(1, len - 2) << "\n";
    }
    else
    {
        cout << "CE\n";
    }
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}