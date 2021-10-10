class floodFill {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
      //if the grid is of the same color 
        if(image[sr][sc] == newColor) return image;
        fill(image,sr,sc,image[sr][sc], newColor);
        
        return image;
        
    }
  
    public void fill(int[][] image, int sr, int sc, int color, int newColor){
      //constraints
        if( sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length|| image[sr][sc] != color ){
            return;
        }
        image[sr][sc] = newColor;
      // 4- way direction up, down, left and right recursive calls for DFS
        fill(image, sr-1, sc, color, newColor);
        fill(image, sr+1, sc, color, newColor);
        fill(image, sr, sc-1, color, newColor);
        fill(image, sr, sc+1, color, newColor);
    }
}
