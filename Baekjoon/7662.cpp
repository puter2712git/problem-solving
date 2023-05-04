#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int T;
int k;
string command;


priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> Q_less;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q_greater;
bool is_saved[1000001];
int count;

vector<string> parse_command(string &command)
{
    stringstream ss(command);
    vector<string> ret;

    string token;
    while (getline(ss, token, ' ')) {
        ret.push_back(token);
    }

    return ret;
}

void check_command(int index)
{
    vector<string> tokens = parse_command(command);

    if (tokens[0] == "I") {
        Q_less.push({ stoi(tokens[1]), index });
        Q_greater.push({ stoi(tokens[1]), index });
        is_saved[index] = true;

        count++;
    }

    if (tokens[0] == "D" && count > 0) {
        if (tokens[1] == "1") {
            while (!Q_less.empty() && !is_saved[Q_less.top().second]) Q_less.pop();

            is_saved[Q_less.top().second] = false;
            Q_less.pop();
        }
        if (tokens[1] == "-1") {
            while (!Q_greater.empty() && !is_saved[Q_greater.top().second]) Q_greater.pop();

            is_saved[Q_greater.top().second] = false;
            Q_greater.pop();
        }

        count--;

        if (count == 0) {
            while (!Q_less.empty())     Q_less.pop();
            while (!Q_greater.empty())  Q_greater.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        cin >> k;
        cin.ignore();
        
        while (!Q_less.empty())     Q_less.pop();
        while (!Q_greater.empty())  Q_greater.pop();
        count = 0;

        for (int j = 0; j < k; j++) {
            getline(cin, command);
            is_saved[j] = false;
            
            check_command(j);
        }

        while (!Q_less.empty() && !is_saved[Q_less.top().second]) Q_less.pop();
        while (!Q_greater.empty() && !is_saved[Q_greater.top().second]) Q_greater.pop();

        if (count == 0) {
            cout << "EMPTY\n";
        } else {
            cout << Q_less.top().first << " " << Q_greater.top().first << "\n";
        }
    }

    return 0;
}