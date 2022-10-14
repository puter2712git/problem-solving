import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  numbers = list(map(int, input().rstrip().split()))
  print(sum(numbers))