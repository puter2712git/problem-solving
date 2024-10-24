#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int K;
vector<int> sensors;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> K;
    sensors = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sensors[i];
    }

    sort(sensors.begin(), sensors.end(), less<int>());

    vector<int> distances(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        distances[i] = sensors[i + 1] - sensors[i];
    }

    sort(distances.begin(), distances.end(), less<int>());

    int answer = 0;
    for (int i = 0; i < N - K; i++)
    {
        answer += distances[i];
    }

    cout << answer << "\n";

    return 0;
}