class Solution:
    def romanToInt(self, s: str) -> int:
      #create hashmap
        roman = { 'I' : 1, 'V': 5, "X": 10, "L" :50, "C":100, "D": 500, "M": 1000}
        integer = 0
        for i, _ in enumerate(s):
  
          #compare the value of the roman symbol to decide whether to add it as prefix or suffix
            if i+1 < len(s) and roman[s[i]]<roman[s[i+1]]:
                integer -= roman[s[i]]
            else:
                integer += roman[s[i]]
        return integer
                
            
