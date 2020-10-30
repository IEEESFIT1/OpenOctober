import java.util.*;
public class anagrams {
public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-->0){
            String str = sc.next();
            int len = str.length(), count = 0;
            if (len%2!=0){
                System.out.println(-1);
                continue;
            }
            String s1 = str.substring(0,len/2);
            String s2 = str.substring(len/2,len);
            char[] s1Chars = s1.toCharArray();
            for (char c : s1Chars){
                int index = s2.indexOf(c);
                if (index == -1){
                    count++;
                } else {
                    s2 = s2.substring(0,index)+s2.substring(index+1);
                }
            }
            System.out.println(count);
        }
    }
}
