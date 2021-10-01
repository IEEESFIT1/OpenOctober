//Hamming code generator
import java.util.*;
class HammingCodeGen{
	static void print(int ar[]) 
    { 
        for (int i = 1; i < ar.length; i++) { 
            System.out.print(ar[i]); 
        } 
        System.out.println(); 
    } 
    static int[] calculation(int[] ar, int r) 
    { 
        for (int i = 0; i < r; i++) { 
            int x = (int)Math.pow(2, i); 
            for (int j = 1; j < ar.length; j++) { 
                if (((j >> i) & 1) == 1) { 
                    if (x != j) 
                        ar[x] = ar[x] ^ ar[j]; 
                } 
            } 
            System.out.println("p" + x + " = "
                               + ar[x]); 
        } 
        return ar; 
    } 
    static int[] generateCode(String str, int M, int r) 
    { 
        int[] ar = new int[r + M + 1]; 
        int j = 0, k=0; 
        for (int i = 1; i < ar.length; i++) { 
            if (i == Math.pow(2,k)) { 
                ar[i] = 0;
				k++; 
            } 
            else { 
                ar[i] = (int)(str.charAt(j) - '0'); 
                j++; 
            } 
        } 
        return ar; 
    } 
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String str;
		System.out.println("Enter the original message: ");
		str= sc.nextLine();
		int s_len = str.length();
		int p_len=1;
		while(Math.pow(2,p_len) <(s_len+p_len+1)){
			p_len++;		
		}
		int[] arr = generateCode(str, s_len, p_len);
		System.out.println("The redundant(parity) bits added: ");
		arr = calculation(arr,p_len);
		System.out.println("Generated Hamming code: ");
		print(arr);
	}
}
