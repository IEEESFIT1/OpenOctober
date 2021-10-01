//java program to check armstrong number
package Java.Algorithms;
import java.util.Scanner;
public class CheckForArmstrongNo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int temp, result = 0, rem;
        temp = number;
        while(temp > 0) {
            rem = temp % 10;
            temp /= 10;
            result = result + (rem * rem * rem);
        }
        if(number == result) {
            System.out.println(number+" is an armstrong number");
        }
        else {
            System.out.println(number+" is not an armstrong number");
        }
    }
}
