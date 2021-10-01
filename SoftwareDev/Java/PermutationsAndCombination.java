// Permutation and Combination Implementation in java
import java.util.*;
public class PermutationsAndCombination {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int choice,n,r;
	System.out.println("Enter \"n\"- Total no. of objects: ");
	n=sc.nextInt();
	System.out.println("Enter \"r\"- no. of choosing objects: ");
	r=sc.nextInt(); 
	System.out.println("Enter 0: Combination");
	System.out.println("Enter 1: Permutation");
	System.out.println("Enter 2: Both Permutation and Combination");
	choice=sc.nextInt();
	if(choice == 0){
		System.out.println("Combination "+n+"C"+r+" = "+Combinations(n, r));	
	}
	else if(choice == 1){
		System.out.println("Permutation "+n+"P"+r+" = "+Permutations(n, r));	
	}
	else{
		System.out.println("Combination "+n+"C"+r+" = "+Combinations(n, r));	
		System.out.println("Permutation "+n+"P"+r+" = "+Permutations(n, r));	
	}
    }
    public static long factorial(int number){
        if (number==0) {
            return 1;
        }
        return number*factorial(number-1);
    }
    public static long Combinations(int n,int r){
        if(n>r){
            long comb=(factorial(n)/((factorial(r))*(factorial(n-r))));
            return comb;
        }
        return 0;
    }
    public static long Permutations(int n, int r){
        if(n>r){
            return Combinations(n, r)*(factorial(r));
        }
        return 0;
    }
}
