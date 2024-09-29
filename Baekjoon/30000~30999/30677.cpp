#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Magic
{
    long long base;
    long long skill;
    long long s;
    long long p;
};

long long N, K, C;
int R;
vector<Magic> magics;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K >> C >> R;
    magics = vector<Magic>(K + 1);
    for (int i = 1; i <= K; i++)
    {
        cin >> magics[i].base;
    }
    for (int i = 1; i <= K; i++)
    {
        cin >> magics[i].s;
    }
    for (int i = 1; i <= K; i++)
    {
        cin >> magics[i].p;
    }

    int magicNumber;
    int tiredness = 0;
    int combo = 0;
    long long star = 0;
    bool isBroken = false;
    for (int i = 0; i < N; i++)
    {
        cin >> magicNumber;
        if (isBroken)
        {
            continue;
        }

        if (magicNumber == 0)
        {
            tiredness = max(0, tiredness - R);
            combo = 0;
            continue;
        }

        Magic &currMagic = magics[magicNumber];

        tiredness += currMagic.p;
        if (tiredness > 100)
        {
            isBroken = true;
            continue;
        }

        star += floor(currMagic.base * (100 + combo * C) * (100 + currMagic.skill * currMagic.s) * 0.0001);
        currMagic.skill++;
        combo++;
    }

    if (!isBroken)
    {
        cout << star << "\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}