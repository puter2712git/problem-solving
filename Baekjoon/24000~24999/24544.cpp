#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    A = vector<int>(N);

    int favPoint = 0;
    int favPointOutOfMyview = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        favPoint += A[i];
    }

    for (int i = 0; i < N; i++)
    {
        int myview;
        cin >> myview;

        if (myview == 0)
        {
            favPointOutOfMyview += A[i];
        }
    }

    cout << favPoint << "\n";
    cout << favPointOutOfMyview << "\n";

    return 0;
}