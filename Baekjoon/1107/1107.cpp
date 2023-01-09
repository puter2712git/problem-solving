#include <cstdio>
#include <string>

using namespace std;

/// @brief Get the count of the digit
/// @param _channel integer value
/// @return count of the digit
int get_digit_count(int _channel)
{
  return to_string(_channel).length();
}

/// @brief Return true if the @_channel includes the breaked number button
/// @param _channel integer v alue
/// @param _buttons array that saves the breaked button
/// @return boolean value
bool has_breaked_number(int _channel, bool _buttons[])
{
  string channel_str = to_string(_channel);
  int len = channel_str.length();

  for (int i = 0; i < len; i++) {
    if (!_buttons[channel_str[i] - '0']) {
      return true;
    }
  }
  
  return false;
}

/// @brief Get the minimum count of pressing the button
/// @param _channel goal channel
/// @param _buttons array that saves the breaked button
/// @param _nr_breaked the count of the breaked button
/// @return minimum count of pressing the button
int get_button_count(int _channel, bool _buttons[], int _nr_breaked)
{
  int min_count = -1;
  int count;

  // starts at 100 channel
  count = 0;

  count = 100 - _channel;
  count = count > 0 ? count : -count;

  min_count = count;

  for (int i = 0; i <= 1000000; i++) {
    // input base channel by number key
    count = 0;

    if (has_breaked_number(i, _buttons)) {
      continue;
    }

    count = i - _channel;
    count = count > 0 ? count : -count;
    count += get_digit_count(i);

    if (min_count == -1 || min_count > count) {
      min_count = count;
    }
  }

  
  return min_count;
}

int main()
{
  int channel;
  int nr_breaked;
  bool buttons[10];
  for (int i = 0; i < 10; i++) buttons[i] = true;

  scanf("%d", &channel);
  scanf("%d", &nr_breaked);
  for (int i = 0; i < nr_breaked; i++) {
    int button;
    scanf("%d", &button);
    buttons[button] = false;
  }

  printf("%d\n", get_button_count(channel, buttons, nr_breaked));

  return 0;
}