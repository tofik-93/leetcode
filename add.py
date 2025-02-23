def two_sum(nums, target):
     #create a dictionary to store the number and their indices
  num_map = {}
  #Itreate thought the list , kepping teack of index and number
  for i, num in enumerate(nums):
    #Calculate the complemet the number needed to reach the target
     complement = target - num
     #check if th complement is already in the dictionary
     if complement in num_map:
        #if found, return the indicate of the current number and the complement
        return [num_map[complement], i]
     #store the numeber and its index in the dictionary
     num_map[num] = i   
     #this is statement is optional since the problem gurantes a solution
     return []
print(two_sum)([2,7,11,15], 9) # [0,1]