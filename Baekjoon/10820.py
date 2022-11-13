while True:
  try:
    string = list(input())
    
    lower = 0
    upper = 0
    number = 0
    space = 0
    
    for ch in string:
      if ch.islower():
        lower += 1
      
      elif ch.isupper():
        upper += 1
      
      elif ch.isdigit():
        number += 1
        
      else:
        space += 1
    
    print(lower, upper, number, space)
  
  except EOFError:
    break