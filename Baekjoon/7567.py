import sys
input = sys.stdin.readline

bowls = input().rstrip()
prev = ''
height = 0

for i in range(len(bowls)):
  if prev == bowls[i]:
    height += 5
  else:
    height += 10
    prev = bowls[i]

print(height)