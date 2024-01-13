import sys
input = sys.stdin.readline

hour, min = map(int, input().rstrip().split())
time = int(input().rstrip())

min += time

while min > 59:
  min -= 60
  hour += 1

while hour > 23:
  hour -= 24

print(hour, min)