import sys
input = sys.stdin.readline

n = int(input().rstrip())
dp_count = [ None ] * (n + 1)
dp_count[0] = -1
dp_count[1] = 0

for i in range(2, n + 1):
  if i % 3 == 0 and i % 2 == 0:
    dp_count[i] = min(dp_count[i // 3], dp_count[i // 2], dp_count[i - 1]) + 1
  elif i % 3 == 0:
    dp_count[i] = min(dp_count[i // 3], dp_count[i - 1]) + 1
  elif i % 2 == 0:
    dp_count[i] = min(dp_count[i // 2], dp_count[i - 1]) + 1
  else:
    dp_count[i] = dp_count[i - 1] + 1

print(dp_count[n])