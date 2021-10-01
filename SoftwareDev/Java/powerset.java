//Java program to find power set
package Java.Algorithms;
import java.util.Scanner;
public class powerset{
  public static void main (String[] args){
    int n;
    Scanner in= new Scanner(System.in);
    n=in.nextInt();
    int[] set=new int[n];
    for(int i=0;i<n;i++){
      set[i]=in.nextInt();
    } 
    in.close();
    System.out.println("{");
    for(int i=0;i<(1<<n);i++){ 
      System.out.print("{ ");
      for(int j=0;j<n;j++){
        if((i & (1<<j))!=0) 
          System.out.print(set[j]+" ");        
      }
      System.out.print("},\n");
    }
    System.out.println("}");
  }
}
