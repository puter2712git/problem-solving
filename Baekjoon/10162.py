import sys
input = sys.stdin.readline

time = int(input().rstrip())

button = {
  'A': 0, 'B': 0, 'C': 0
}

if time % 10 != 0:
  print(-1)
else:
  while time >= 60 * 5:
    time -= 60 * 5
    button['A'] += 1
  while time >= 60:
    time -= 60
    button['B'] += 1
  button['C'] = time // 10

  for value in button.values():
    print(value, end=' ')