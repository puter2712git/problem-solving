#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int years[3];
    years[0] = 1;
    years[1] = 1;
    years[2] = 1;
    int yearCount = 1;

    int earthYear,
        sunYear, moonYear;
    cin >> earthYear >> sunYear >> moonYear;

    while (true) {
        if (years[0] == earthYear && years[1] == sunYear && years[2] == moonYear) {
            break;
        }

        yearCount++;
        for (int i = 0; i < 3; i++) {
            years[i]++;
        }
        if (years[0] > 15)
            years[0] = 1;
        if (years[1] > 28)
            years[1] = 1;
        if (years[2] > 19)
            years[2] = 1;
    }

    cout << yearCount << "\n";

    return 0;
}