import sys

input = sys.stdin.readline

dp_stair_nums = [ [ 0 for _ in range(0, 10) ] for _ in range(101) ]
dp_stair_nums[1] = [ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 ]
dp_stair_nums[2] = [ 1, 1, 2, 2, 2, 2, 2, 2, 2, 1 ]

n = int(input().rstrip())

for i in range(3, n + 1):
  # when 0 is end
  dp_stair_nums[i][0] = dp_stair_nums[i - 1][1]
  # when 1 is end
  dp_stair_nums[i][1] = dp_stair_nums[i - 1][0] + dp_stair_nums[i - 1][2]
  # when 2 is end
  dp_stair_nums[i][2] = dp_stair_nums[i - 1][1] + dp_stair_nums[i - 1][3]
  # when 3 is end
  dp_stair_nums[i][3] = dp_stair_nums[i - 1][2] + dp_stair_nums[i - 1][4]
  # when 4 is end
  dp_stair_nums[i][4] = dp_stair_nums[i - 1][3] + dp_stair_nums[i - 1][5]
  # when 5 is end
  dp_stair_nums[i][5] = dp_stair_nums[i - 1][4] + dp_stair_nums[i - 1][6]
  # when 6 is end
  dp_stair_nums[i][6] = dp_stair_nums[i - 1][5] + dp_stair_nums[i - 1][7]
  # when 7 is end
  dp_stair_nums[i][7] = dp_stair_nums[i - 1][6] + dp_stair_nums[i - 1][8]
  # when 8 is end
  dp_stair_nums[i][8] = dp_stair_nums[i - 1][7] + dp_stair_nums[i - 1][9]
  # when 9 is end
  dp_stair_nums[i][9] = dp_stair_nums[i - 1][8]
  
print(sum(dp_stair_nums[n]) % 1000000000)