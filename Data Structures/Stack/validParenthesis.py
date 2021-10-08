class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = { ")":"(", "}":"{", "]":"["}
        for i in s:
            if i in mapping:
                top_element = stack.pop() if stack else '#'
                if mapping[i] != top_element:
                    return False
            else:
                # We have an opening bracket, simply push it onto the stack.
                stack.append(i)

        # In the end, if the stack is empty, then we have a valid expression.
        # The stack won't be empty for cases like ((()
        return not stack
