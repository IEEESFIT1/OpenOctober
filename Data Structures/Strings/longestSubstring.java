import java.util.*;
class longestSubstring {
    public static void main(String args[]) {
        int left = 0;
        int right = 0;
        int max = 0;
        String s = "aaaabcacc";
        //to make sure no repeating characters are present in the substring
        HashSet <Character> hash_set = new HashSet();
        //working like a sliding window
        while(right < s.length()){
            // if not present, add it into the substring and increment the scanning
            if(!hash_set.contains(s.charAt(right))){
                hash_set.add(s.charAt(right));
                right ++;
                max = Math.max(hash_set.size(),max);
            }
            //else drop the left most character 
            else{
                hash_set.remove(s.charAt(left));
                left ++;
            }
        }
        System.out.println(max);
    }
}