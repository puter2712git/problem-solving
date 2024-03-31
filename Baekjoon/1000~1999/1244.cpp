#include <iostream>
#include <vector>

using namespace std;

void UpdateSwitches(vector<int>& switches, int studentType, int switchIndex)
{
    if (studentType == 1) {
        for (int i = 1; i < switches.size(); i++) {
            if (i % switchIndex == 0) {
                switches[i] = switches[i] == 0 ? 1 : 0;
            }
        }
    } else if (studentType == 2) {
        int step = 0;
        switches[switchIndex] = switches[switchIndex] == 0 ? 1 : 0;

        while (true) {
            step++;
            if (switchIndex - step < 1 || switchIndex + step > switches.size() - 1) {
                break;
            }
            if (switches[switchIndex - step] != switches[switchIndex + step]) {
                break;
            }

            switches[switchIndex - step] = switches[switchIndex - step] == 0 ? 1 : 0;
            switches[switchIndex + step] = switches[switchIndex + step] == 0 ? 1 : 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int switchLength;
    vector<int> switches;
    switches.push_back(0);

    cin >> switchLength;
    for (int i = 0; i < switchLength; i++) {
        int tmp;
        cin >> tmp;
        switches.push_back(tmp);
    }

    int studentLength;
    cin >> studentLength;
    for (int i = 0; i < studentLength; i++) {
        int studentType;
        int switchIndex;
        cin >> studentType >> switchIndex;

        UpdateSwitches(switches, studentType, switchIndex);
    }

    for (int i = 1; i <= switchLength; i++) {
        cout << switches[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }
    cout << "\n";

    return 0;
}