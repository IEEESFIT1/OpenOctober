/*
Optimal solution -  
1 2 3 4 5 6
Divide the array into two and swap
4 5 6 1 2 3 
now reverse the two halves
6 5 4 3 2 1 

Use recursion to deal with the halves.

*/
class rotateArray {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums , 0, nums.length-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.length-1);
    }
  // reverse function
    public void reverse(int[] nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end]= temp;
            start ++;
            end --;
        }
    }
}

/*
Naive solution - 

Use an extra array data structure to do the same

class rotateArray{
      public void rotate(int[] nums, int k){
          int len = nums.length;
          int a[ ] = new int [len];
          for(int i = 0; i < len; i++){ 
              a[i] = nums[len-i-1];
          
          }
          return nums;
      
      }
}



*/
