import sys, math
input = sys.stdin.readline

num = int(input().rstrip())

if (num & (num - 1) == 0):
  print(1)
else:
  print(0)