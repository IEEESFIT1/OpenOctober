//Java Program for automorphic number
package Java.Algorithms;
import java.util.*;
public class Automorphic{
    static boolean isAutomorphic(int n){
        int s=n*n;  
        while(n>0){ 
            if (n%10!=s%10) 
                return false; 
            n/=10; 
            s/=10; 
        } 
        return true; 
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number: ");
        int n=sc.nextInt();
        if(isAutomorphic(n))
            System.out.println("Automorphic Number");
        else     
            System.out.println("Not an Automorphic Number");
    }
}
