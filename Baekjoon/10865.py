import sys
input = sys.stdin.readline

student, testcase = map(int, input().rstrip().split())
friend_list = [0 for i in range(student)]

for i in range(testcase):
  a, b = map(int, input().rstrip().split())
  friend_list[a - 1] += 1
  friend_list[b - 1] += 1

for friend in friend_list:
  print(friend)