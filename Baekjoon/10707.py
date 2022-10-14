import sys
input = sys.stdin.readline

x_fee = int(input().rstrip())
y_fee = int(input().rstrip())
y_limit = int(input().rstrip())
y_add_fee = int(input().rstrip())
used_water = int(input().rstrip())

x_fee = used_water * x_fee
if used_water > y_limit:
  y_fee = y_fee + y_add_fee * (used_water - y_limit)

print(min(x_fee, y_fee))