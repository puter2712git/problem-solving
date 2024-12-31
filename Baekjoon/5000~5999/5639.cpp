#include <iostream>

using namespace std;

int i;
int nodes[10000];

void Trace(int begin, int end)
{
    if (begin >= end) return;

    for (i = begin + 1; i < end; i++)
    {
        if (nodes[begin] < nodes[i]) break;
    }

    Trace(begin + 1, i);
    Trace(i, end);
    cout << nodes[begin] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int index = 0;
    int n;
    while (cin >> n)
    {
        nodes[index] = n;
        index += 1;
    }

    Trace(0, index);

    return 0;
}