import sys
input = sys.stdin.readline

n = int(input().rstrip())
max_score = 0
min_submit = 0
min_upload = 0
win_index = 0

for i in range(n):
  score, submit, upload = map(int, input().rstrip().split())
  
  if i == 0:
    max_score, min_submit, min_upload, win_index = score, submit, upload, 0
  else:
    if max_score < score:
      max_score, min_submit, min_upload, win_index = score, submit, upload, i
    elif max_score == score:
      if min_submit > submit:
        max_score, min_submit, min_upload, win_index = score, submit, upload, i
      elif min_submit == submit:
        if min_upload > upload:
          max_score, min_submit, min_upload, win_index = score, submit, upload, i
  
print(win_index + 1)