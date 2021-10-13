class longestCommonPrefix:
    def longestCommonPrefixFn(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        common = min(strs, key=len) # get shortest word in strs

        while common:
            for word in strs:
                if word.startswith(common):
                    continue
                else:
                    common = common[:-1]
                    break
            else:
                return common
        return ""
        
