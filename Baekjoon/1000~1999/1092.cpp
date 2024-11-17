#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> crane;
vector<int> box;

void Setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        crane.push_back(n);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int m;
        cin >> m;
        box.push_back(m);
    }
}

void Solve()
{
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());

    if (crane.back() < box.back())
    {
        cout << -1;
        return;
    }

    int cnt = 0;
    while (!box.empty())
    {
        cnt++;
        for (int i = crane.size() - 1; i >= 0; i--)
        {
            for (int j = box.size() - 1; j >= 0; j--)
            {
                if (crane[i] >= box[j])
                {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }

    cout << cnt;
}

int main()
{
    Setup();
    Input();
    Solve();

    return 0;
}
