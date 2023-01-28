#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;

deque<int> parse_arr(const string &_arr)
{
    deque<int> ret;

    string tmp;
    int len = _arr.size();

    for (int i = 1; i < len - 1; i++) {
        if (_arr[i] == ',') {
            ret.push_back(stoi(tmp));
            tmp.clear();

            continue;
        }

        if (isdigit(_arr[i])) {
            tmp.push_back(_arr[i]);
        }
    }

    if (!tmp.empty())
        ret.push_back(stoi(tmp));

    return ret;
}

void translate(const string &_func, const string &_arr)
{
    deque<int> array = parse_arr(_arr);

    int len = _func.size();
    int r_cnt = 0;

    for (int i = 0; i < len; i++) {
        switch (_func[i]) {
        case 'R':
            r_cnt++;
            break;
        case 'D':
            if (array.empty()) {
                cout << "error" << '\n';
                return;
            }

            if (r_cnt % 2 == 0) {
                array.pop_front();
            } else {
                array.pop_back();
            }
            break;
        }
    }

    int array_len = array.size();

    cout << '[';
    if (r_cnt % 2 == 0) {
        for (int i = 0; i < array_len; i++) {
            cout << array[i];

            if (i == array_len - 1) break;

            cout << ',';
        }
    } else {
        for (int i = array_len - 1; i >= 0; i--) {
            cout << array[i];

            if (i == 0) break;

            cout << ',';
        }
    }
    cout << ']';
    cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int nr_testcase;

    string func;

    int arr_len;
    string arr;

	cin >> nr_testcase;

	for (int i = 0; i < nr_testcase; i++)
	{
        cin >> func;
        cin >> arr_len;
        cin >> arr;

        translate(func, arr);
	}

    return 0;
}