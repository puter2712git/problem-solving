#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int score = 0;
    int type;
    int ballCount = 0;
    bool base[3] = {false, false, false};
    while (N--)
    {
        cin >> type;

        switch (type)
        {
        case 1:
            ballCount++;
            break;

        case 2:
            ballCount = 0;
            if (base[0] && base[1] && base[2])
            {
                base[2] = false;
                score++;
            }
            if (base[0] && base[1])
            {
                base[1] = false;
                base[2] = true;
            }
            if (base[0])
            {
                base[1] = true;
            }
            base[0] = true;
            break;

        case 3:
            ballCount++;
            if (base[2])
            {
                base[2] = false;
                score++;
            }
            if (base[1])
            {
                base[1] = false;
                base[2] = true;
            }
            if (base[0])
            {
                base[0] = false;
                base[1] = true;
            }
        }

        if (ballCount == 4)
        {
            ballCount = 0;
            if (base[0] && base[1] && base[2])
            {
                base[2] = false;
                score++;
            }
            if (base[0] && base[1])
            {
                base[1] = false;
                base[2] = true;
            }
            if (base[0])
            {
                base[1] = true;
            }
            base[0] = true;
        }
    }

    cout << score << "\n";

    return 0;
}