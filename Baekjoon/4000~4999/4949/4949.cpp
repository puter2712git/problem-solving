#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

bool is_balanced(char *_str)
{
  int len = strlen(_str);
  stack<char> parenthesis;

  for (int i = 0; i < len; i++) {
    /* 여는 괄호일 때는 스택에 push */
    if (_str[i] == '(' || _str[i] == '[') {
      parenthesis.push(_str[i]);
      continue;
    }

    /* 닫힌 괄호를 만났을 때 종류에 따라 return 또는 계속 탐색*/
    if (_str[i] == ')' || _str[i] == ']') {
      if (parenthesis.empty()) {
        return false;
      }
    }

    if (_str[i] == ')') {
      if (parenthesis.top() == '(') {
        parenthesis.pop();
        continue;
      }
      else {
        return false;
      }
    }

    if (_str[i] == ']') {
      if (parenthesis.top() == '[') {
        parenthesis.pop();
        continue;
      }
      else {
        return false;
      }
    }
  }

  if (!parenthesis.empty()) {
    return false;
  }
  
  return true;
}

int main()
{
  while (true) {
    char str[101];
    scanf("%[^\n]s", str);
    getchar();

    if (!strcmp(str, ".")) {
      break;
    }

    if (is_balanced(str)) {
      printf("yes\n");
    }
    else {
      printf("no\n");
    }
  }

  return 0;
}