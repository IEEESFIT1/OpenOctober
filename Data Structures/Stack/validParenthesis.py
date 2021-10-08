class Solution:
    def isValid(self, s: str) -> bool:
      #hashmap- dictionary kind of datastructure to form a pair
        hm = {")": "(", "}":"{", "]":"["}
        stack = []
        for i in s:
            if i in hm:
              #pop from the stack if the parentheses is complete
                if stack and stack[-1] == hm[i]:
                    stack.pop()
                else:
                    return False
            else:
              #add to the stack- push- if the parantheses is new
                stack.append(i)
        
        #if stack is empty, then the parentheses are complete and paired.
        if stack == []:
            return True
        else:
            return False
                
                
