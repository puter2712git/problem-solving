import sys
input = sys.stdin.readline

testcase = int(input().rstrip())
for i in range(testcase):
  candy_num, brother_num = map(int, input().rstrip().split())
  
  print('You get {} piece(s) and your dad gets {} piece(s).'.format(candy_num // brother_num, candy_num % brother_num))