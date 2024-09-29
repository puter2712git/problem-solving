#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> drinks;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    drinks = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> drinks[i];
    }

    sort(drinks.begin(), drinks.end(), less<int>());

    double drinkSize = drinks[N - 1];
    for (int i = 0; i < N - 1; i++)
    {
        drinkSize += drinks[i] * 0.5;
    }

    cout << drinkSize << "\n";

    return 0;
}