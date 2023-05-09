#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }

        return abs(a) > abs(b);
    }
};

int main()
{
    priority_queue<int, vector<int>, compare> pq_abs;

    int op_count;
    int n;

    cin >> op_count;
    while (op_count--) {
        cin >> n;

        if (n == 0) {
            if (pq_abs.empty()) {
                cout << "0" << "\n";
                continue;
            }

            int tmp = pq_abs.top();
            pq_abs.pop();
            cout << tmp << "\n";
        }

        else {
            pq_abs.push(n);
        }
    }

    return 0;
}