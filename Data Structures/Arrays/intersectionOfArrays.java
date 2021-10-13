class intersectionOfArrays{
    public int[] intersect(int[] nums1, int[] nums2) {
      //sort
        Arrays.sort(nums1);
        Arrays.sort(nums2);
      //pointer for array one
        int i = 0;
      //pointer for array two
        int j = 0;
      //pointer to find the intersection range
        int k = 0;
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] < nums2[j]){
                i ++;
            }
            else if(nums1[i] > nums2[j]){ 
                j++; 
            }
            else{ 
                nums1[k++] = nums1[i++];
                j++;
            }
        }
        return Arrays.copyOfRange(nums1, 0, k);
            
        }
    }
