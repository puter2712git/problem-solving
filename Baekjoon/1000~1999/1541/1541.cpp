#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


/// @brief Parse the expression to operand and operator
/// @param _target expression string
/// @param _parsed_str empty vector with string
void parse_expression(string _target, vector<string> &_parsed_str)
{
  int len = _target.length();
  int start_index = 0;

  for (int i = 0; i < len; i++) {
    if (!isdigit(_target[i])) {
      _parsed_str.push_back(_target.substr(start_index, i - start_index));
      _parsed_str.push_back(_target.substr(i, 1));
      start_index = i + 1;
    }
  }
  _parsed_str.push_back(_target.substr(start_index, len - start_index));
}


/// @brief Get minimum value of parsed expression
/// @param _parsed_str parsed expression, vector with string
/// @return integer value
int get_min_value(vector<string> &_parsed_str)
{
  int ret = 0;
  bool is_minus = false;

  for (int i = 0; i < _parsed_str.size(); i++) {
    if (atoi(_parsed_str[i].c_str())) {
      if (is_minus) {
        ret -= stoi(_parsed_str[i]);
      } else {
        ret += stoi(_parsed_str[i]);
      }
    }

    if (_parsed_str[i] == "-") {
      is_minus = true;
    }
  }

  return ret;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string expression;
  cin >> expression;

  vector<string> parsed_str;
  parse_expression(expression, parsed_str);

  cout << get_min_value(parsed_str) << '\n';

  return 0;
}