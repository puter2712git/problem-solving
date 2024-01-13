import sys
input = sys.stdin.readline

hour, min, sec = map(int, input().rstrip().split())
time = int(input())

sec += time

while sec > 59:
  sec -= 60
  min += 1

while min > 59:
  min -= 60
  hour += 1

while hour > 23:
  hour -= 24

print(hour, min, sec)