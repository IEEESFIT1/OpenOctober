/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S).
Palindrome string: A string which reads the same backwards. More formally, S is palindrome 
if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).
*/
class LongestPalindrome{
    static String longestPalin(String S){
        // code here
        
        int i,n = S.length();
        
        boolean table[][] = new boolean[n][n];
        int maxLength = 1;
        for(i = 0; i< n;i++)
           table[i][i] = true;
          
        
        int startIndex = 0;
        for(i = 0;i<n-1;i++)
        {
            if(S.charAt(i) == S.charAt(i+1))
            {
                table[i][i+1] = true;
                int ln = 2;
                if(maxLength < ln)
                {
                    maxLength = 2;
                    startIndex = i;
                }
            }
        }
        
  
       
        int subLen ,j; //substring length 
        for(subLen = 3; subLen <= n ; subLen++)
        {
            //starting index
            for(i=0;i<n-subLen+1;i++)
            {
                j = i + subLen -1;
                if(table[i+1][j-1] && S.charAt(i) == S.charAt(j))
                {
                    table[i][j] = true;
                    
                    if(subLen > maxLength)
                    {
                        maxLength = subLen;
                        startIndex = i;
                    }
                }
            }
        }
        return S.substring(startIndex,startIndex+maxLength);
        
        
    }
}
