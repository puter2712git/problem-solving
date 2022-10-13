import sys
input = sys.stdin.readline

testcase = int(input().rstrip())
for i in range(testcase):
  price = float(input().rstrip())
  print('${:.2f}'.format(price * 80 / 100))