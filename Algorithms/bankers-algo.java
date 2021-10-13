import java.io.*;
import java.util.*;

class Bankers {
    int allocation[][] = {{0, 1, 0},
                        {2, 0, 0},
                        {3, 0, 2},
                        {2, 1, 1},
                        {0, 0, 2}};
    int max[][] = {{7, 5, 3},
                {3, 2, 2},
                {9, 0, 2},
                {2, 2, 2},
                {40, 30, 30}};
    int available[] = {3, 3, 2}, totalInstances[] = {10, 5, 7};
    int numberOfResources = 3, numberOfProcesses = 5;
    // request is the need matrix: need = max - allocated;
    int request[][] = new int[numberOfProcesses][numberOfResources];
    boolean done[] = new boolean[numberOfProcesses]; 
    int cnt = 0;
    Scanner s = new Scanner(System.in);
    
    void processInput() {
        System.out.println("\n\t\t Welcome to Banker's Algorithm \n");
        
        System.out.print("Do you want to input the values? [0/1]: ");
        if(s.nextInt() == 1) {
            
            System.out.print("\nEnter the number of processes: ");
            numberOfProcesses = s.nextInt();
            System.out.print("\nEnter the number of resources: ");
            numberOfResources = s.nextInt();
            
            int totalInstances[] = new int[numberOfResources];
            System.out.println("\nEnter total number of instances per resource:");
            for(int i = 0; i < numberOfResources; ++i) {
                System.out.print("Enter total number of instances of resource " + (i + 1) + ": ");
                totalInstances[i] = s.nextInt();
            }
            System.out.println("");
            int allocation[][] = new int[numberOfProcesses][numberOfResources];
            for(int i = 0; i < numberOfProcesses; i++) {
                System.out.print("Enter allocated instances for Process " + (i + 1) + ": ");
                for(int j = 0; j < numberOfResources; j++) {
                    allocation[i][j] = s.nextInt();
                }
            }
            System.out.println("");
            int max[][] = new int[numberOfProcesses][numberOfResources];
            for(int i = 0; i < numberOfProcesses; i++) {
                System.out.print("Enter maximum  instances for Process " + (i + 1) + ": ");
                for(int j = 0; j < numberOfResources; j++) {
                    max[i][j] = s.nextInt();
                }
            }
            // request is the need matrix: need = max - allocated;
            int request[][] = new int[numberOfProcesses][numberOfResources];
            int available[] = new int[numberOfResources];
            System.out.println("\nEnter available instances per resource:");
            for(int i = 0; i < numberOfResources; ++i) {
                System.out.print("\nEnter number of instances AVAILABLE of resource " + (i + 1) + ": ");
                available[i] = s.nextInt();
            }            
        }
        iteratingProcesses();
    }

    void printMatrix(int[][] arr) {
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; i < arr[0].length; j++) {
                System.out.print( arr[i][j] + " ");
            }
            System.out.println("");
        }
    }
    
    void computeRequests() {
        System.out.println("\nThe Max Matrix is: ");
        for(int i = 0; i < allocation.length; ++i) {
            for(int j = 0; j < allocation[i].length; ++j) {
                System.out.print( max[i][j] + " ");
            }
            System.out.println("");
        }

        System.out.println("\nThe Allocation Matrix is: ");
        for(int i = 0; i < allocation.length; ++i) {
            for(int j = 0; j < allocation[i].length; ++j) {
                System.out.print( allocation[i][j] + " ");
            }
            System.out.println("");
        }

        System.out.println("\nThe calculated need matrix is: ");
        for(int i = 0; i < allocation.length; ++i) {
            for(int j = 0; j < allocation[i].length; ++j) {
                request[i][j] = max[i][j] - allocation[i][j];
                System.out.print( request[i][j] + " ");
            }
            System.out.println("");
        }
    }

    void iteratingProcesses() {
        computeRequests();
        int prev = -1;
        while(prev != cnt && cnt != numberOfProcesses) {
            prev = cnt;
            for(int i = 0; i < request.length; ++i) {
                if(!done[i]) {
                    boolean ok = true;
                    for(int j = 0; j < request[0].length; ++j) {
                        if(request[i][j] > available[j]) {
                            ok = false;
                            break;
                        }
                    }
    
                    if(ok) {
                        System.out.println("\n\nProcess "+ (i + 1) +" can be allocated the resources...");
					    System.out.println("Process Terminated. Releasing resources...");
                        System.out.print("Process " + (i + 1) + ": ");
                        for(int j = 0; j < available.length; ++j) {
                            System.out.print(available[j] + " ");
                        }
                        System.out.print(" + ");
                        for(int j = 0; j < allocation[0].length; ++j) {
                            System.out.print(allocation[i][j] + " ");
                        }
                        
                        System.out.print(" = ");
                        for(int j = 0; j < request[0].length; ++j) {
                            available[j] += allocation[i][j];
                            System.out.print(available[j] + " ");
                        }
                        System.out.println("");
                        
                        done[i] = true;
                        cnt += 1;
                    }
                }
            }
            if(prev == cnt) {
                System.out.println("\nNone of the remaining processes can be allocated the required resources. \nTerminating iteration...");
            }
        }

        if(cnt == numberOfProcesses) {
            System.out.println("All processes terminated. \nSafe");
        } else {
            System.out.println("\nUnSafe");
        }
    }

}

class BankersAlgorithm {
    public static void main(String args[]) throws IOException
    {
        Bankers b = new Bankers();
        b.processInput();
    }
}