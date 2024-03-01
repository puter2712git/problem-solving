#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Monitor {
    int index;
    int ppiCompValue;
};

inline int GetVirtualPPI(int width, int height)
{
    return width * width + height * height;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int monitorCount;
    vector<Monitor> monitors;

    cin >> monitorCount;

    for (int i = 1; i <= monitorCount; i++) {
        int width, height;
        cin >> width >> height;

        int ppi = GetVirtualPPI(width, height);
        Monitor newMonitor = {
            i,
            ppi
        };
        monitors.push_back(newMonitor);
    }

    sort(monitors.begin(), monitors.end(), [](Monitor& first, Monitor& second) -> bool {
        if (first.ppiCompValue == second.ppiCompValue) {
            return first.index < second.index;
        }
        return first.ppiCompValue > second.ppiCompValue;
    });

    for (auto iter = monitors.begin(); iter != monitors.end(); iter++) {
        cout << iter->index << "\n";
    }

    return 0;
}