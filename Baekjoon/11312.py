import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  a, b = map(int, input().rstrip().split())
  print(int((a * a) / (b * b)))