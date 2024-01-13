import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  day_count = int(input().rstrip())
  profit = 0
  
  for j in range(day_count):
    a, b, c = map(int, input().rstrip().split())
    
    max_profit = max(max(a, b), c)
    if max_profit > 0:
      profit += max_profit
  
  print(profit)