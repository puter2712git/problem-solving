#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;

    int element;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> element;
            pq.push(element);
        }

        while (pq.size() > N) {
            pq.pop();
        }
    }

    cout << pq.top() << "\n";

    return 0;
}