//Prime Factors of A Number using Recursion
import java.util.*;
public class PrimeFactors {
	static int i=2;
	public static void prime(int num) {
		if(i<=num) {
			if(num%i==0) {
				System.out.print(i+" ");
				num=num/i;
			}
			else
			{
				i++;
			}
			prime(num);      //Recursion
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number: ");
		int n = sc.nextInt();
		sc.close();
		System.out.println("The Prime Factors of "+ n + " are:\n");
		prime(n);
	}
}