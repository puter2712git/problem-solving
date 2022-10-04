import sys
input = sys.stdin.readline

nums = list(map(int, input().rstrip().split()))
nums.sort()

print(nums[1])