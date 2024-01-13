import sys

input = sys.stdin.readline

num = int(input().rstrip())

dp_square = [ _ for _ in range(num + 1) ]

for i in range(2, num + 1):
  for j in range(1, i):
    if j * j > i:
      break
    if dp_square[i] > dp_square[i - j * j] + 1:
      dp_square[i] = dp_square[i - j * j] + 1

print(dp_square[num])