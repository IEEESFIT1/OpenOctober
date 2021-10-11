class threeSumClosest:
    def threeSumClosestFn(self, nums: List[int], target: int) -> int:
      #just a random high value
        best_sum = 100000
        sum = 0
        nums.sort()
        for i in range(0,len(nums)-2):
            if nums[i] == nums[i-1] and i>0:
                continue
            
            lower = i+1
            upper = len(nums) - 1
            #traversing the array
            while(lower<upper):
                sum = nums[i] + nums[lower] + nums[upper]
                
                if sum == target:
                    return sum
                #comparing the new sum value
                if abs(target-sum) < abs(target-best_sum):
                    best_sum = sum
                    
                if sum <= target:
                    lower += 1
                    while(nums[lower]) == nums[lower-1] and lower<upper:
                        lower += 1
                        
                else:
                    upper -= 1
                    
                
            
        return best_sum
                        
                    
