import sys
input = sys.stdin.readline

s = int(input().rstrip())
plus = 1
count = 0

while s >= plus:
  s -= plus
  plus += 1
  count += 1

print(count)