//Java Program to implement Collatz conjecture
import java.util.*;  
class CollatzSequence  
{  
    static boolean isToOneRec(int n, HashSet<Integer> s)  
    { 
        if (n == 1)  
        { 
            return true; 
        }  
        if (s.contains(n))  
        { 
            return false; 
        } 
        return (n % 2 == 1) ? isToOneRec(3 * n + 1, s) 
                : isToOneRec(n / 2, s); 
    } 
    static boolean isToOne(int n)  
    { 
        HashSet<Integer> s = new HashSet<Integer>(); 
        return isToOneRec(n, s); 
    } 
    public static void main(String[] args)  
    { 
        int n = 5; 
        if (isToOne(n))  
        { 
            System.out.print("Yes"); 
        }  
        else 
        { 
            System.out.print("No"); 
        } 
    } 
} 
