#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int T;
int n;
vector<int> an;

vector<int> Doocci(vector<int> &seq)
{
    vector<int> ret;

    for (int i = 0; i < n - 1; i++)
    {
        ret.push_back(abs(seq[i] - seq[i + 1]));
    }
    ret.push_back(abs(seq[0] - seq[n - 1]));

    return ret;
}

bool IsZero(vector<int> &seq)
{
    for (int i = 0; i < n; i++)
    {
        if (seq[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        cin >> n;
        an = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            cin >> an[i];
        }

        int loopCount = 0;
        bool isZero = false;
        while (loopCount < 1000)
        {
            loopCount++;
            an = Doocci(an);

            if (IsZero(an))
            {
                isZero = true;
                break;
            }
        }

        if (isZero)
        {
            cout << "ZERO\n";
        }
        else
        {
            cout << "LOOP\n";
        }
    }

    return 0;
}
