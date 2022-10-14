import sys, math
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  cookie_num, cookie_eat_per_day = map(int, input().rstrip().split())
  
  day_count = math.ceil(cookie_num / cookie_eat_per_day)
  print(day_count)