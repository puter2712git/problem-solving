#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string word;

  while (true) {
    cin >> word;

    if (word == "0") {
      break;
    }
    
    string str1 = word.substr(0, word.length() / 2);
    reverse(word.begin(), word.end());
    string str2 = word.substr(0, word.length() / 2);

    if (str1 == str2) {
      cout << "yes" << endl;
    }
    else {
      cout << "no" << endl;
    }
  }

  return 0;
}