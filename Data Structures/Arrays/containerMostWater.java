class containerMostWater {
    public int maxArea(int[] height) {
       
        
        int res = 0;
        
        int i = 0, j = height.length-1;
        
        while(i != j) {
          //i is the lowest bar before another max area is encountered
            if(height[i] < height[j]) {
                res = Math.max(res, height[i] * (j-i));
                i++;
            }
          // maximum of the area is stored and reassigned
            else{
                res = Math.max(res, height[j] * (j-i));
                j--;
            }
         
        }
        return res;
        
    }
    }

