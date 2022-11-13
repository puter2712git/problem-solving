import sys

input = sys.stdin.readline

string = list(input().rstrip())
suffix = []

for i in range(len(string)):
  suffix.append(''.join(string[len(string) - i - 1:]))

suffix.sort()

print('\n'.join(suffix))