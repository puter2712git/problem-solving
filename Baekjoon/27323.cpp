#include <iostream>

using namespace std;

int get_area_of_rectangle(int a, int b)
{
    return a * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A, B;

    cin >> A;
    cin >> B;

    cout << get_area_of_rectangle(A, B) << "\n";

    return 0;
}