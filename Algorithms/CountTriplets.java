/*
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets: 
1 + 2 = 3 and 3 +2 = 5 
*/
class CountTriplets {
    int countTriplet(int arr[], int n) {
        Arrays.sort(arr);
        int i,j,k,count=0;
        for(i = n-1;i >=0 ;i--)
        {
            j = 0;
            k = i - 1;
            while(j < k)
            {
                if(arr[i] == arr[j]+arr[k])
                {
                    count++;
                    j +=1;
                    k -= 1;
                }
                else if (arr[i]>arr[j]+arr[k])
                    j += 1;
                else
                    k -= 1;
            }
        }
        return count; 
    }
}
