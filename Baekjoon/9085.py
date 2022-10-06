import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  n = int(input().rstrip())
  nums = list(map(int, input().rstrip().split()))
  
  print(sum(nums))