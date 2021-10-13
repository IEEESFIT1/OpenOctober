class firstLastPostion:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
      #return null null if not present
        if target not in nums:
            return ([-1,-1])
          #first index
        first = nums.index(target)
        #last index
        last = 0
        #assign new value to last
        for i in range(len(nums)-1,first,-1):
            if  nums[i] is target:
                last = i
                break
        
        if last == 0:
            return [first,first]
        
        return([first,last])
