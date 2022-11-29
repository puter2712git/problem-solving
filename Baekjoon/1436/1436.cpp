#include <iostream>

using namespace std;

// @_number에 666이 포함되어 있다면 true를 return
bool is666Included(int _number) {
  string num = to_string(_number);

  if (num.find("666") == string::npos) {
    return false;
  }
  else {
    return true;
  }
}


int main() {
  int n;
  int number = 665;

  cin >> n;

  // 666이 포함되는 n번째로 큰 수를 찾기
  while (n > 0) {
    number++;

    while (!is666Included(number)) {
      number++;
    }
    n--;
  }

  cout << number << endl;

  return 0;
}