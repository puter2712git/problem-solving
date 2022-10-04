import sys


import sys
input = sys.stdin.readline

price, snack_num, money = map(int, input().rstrip().split())

if (price * snack_num - money < 0):
  print(0)
else:
  print(price * snack_num - money)