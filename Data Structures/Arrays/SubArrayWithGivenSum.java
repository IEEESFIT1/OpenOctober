/* Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.*/
 /* Brute force method*/

class SubArrayWithGivenSum.
{
    //Function to find a continuous sub-array which adds up to a given number.
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) 
    {
        // Your code here
        ArrayList<Integer> al = new ArrayList<Integer>();
        int i,startIndex=-1,endIndex=-1,sum=0,j,flag=0;
        for(i = 0;i<n;i++)
        {
            sum = 0;
            startIndex = i+1;
            for(j=i;j<n;j++)
            {
                sum += arr[j];
                if(sum == s)
                {
                    
                    endIndex = j+1;
                    flag = 1; 
                    break;
                }
                if(sum > s)
                    break;
            }
            if(flag == 1)
                break;
        }
        if(endIndex == -1)
        {
            al.add(endIndex);
            return al;
        }
        al.add(startIndex);
        al.add(endIndex);
        return al;
        
    }
}
