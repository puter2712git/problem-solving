import sys
input = sys.stdin.readline

numbers = list(map(int, input().rstrip().split()))

print(sum(numbers))