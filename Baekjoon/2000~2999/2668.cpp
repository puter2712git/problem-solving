#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int N;
vector<int> table;
vector<bool> isVisited;
vector<int> answer;

void Dfs(int startNum)
{
    stack<int> s;
    s.push(table[startNum]);
    isVisited[startNum] = true;

    while (!s.empty())
    {
        int popped = s.top();
        s.pop();

        if (isVisited[popped])
        {
            if (startNum == popped)
            {
                answer.push_back(popped);
            }
            break;
        }

        s.push(table[popped]);
        isVisited[popped] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    table = vector<int>(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> table[i];
    }

    for (int i = 1; i <= N; i++)
    {
        isVisited = vector<bool>(N + 1, false);
        Dfs(i);
    }

    cout << answer.size() << "\n";
    for (int num : answer)
    {
        cout << num << "\n";
    }

    return 0;
}