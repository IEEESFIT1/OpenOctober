class maxAreaIsland {
    int[][] grid;
    boolean[][] seen;
    
    public int area( int r, int c){
      //constraints for the recursive call
        if(r<0 || r >= grid.length || c< 0 || c>= grid[0].length|| seen[r][c] || grid[r][c] == 0){
            return 0;
        }
      //visiting a grid
        seen[r][c] = true;
      // travelling four directionally
        return(1+area(r+1,c)+area(r-1,c)+area(r,c+1)+area(r,c-1));
    }
    
    
    public int maxAreaOfIsland(int[][] grid) {
        this.grid  = grid;
      // the grid which has been visited
        seen = new boolean[grid.length][grid[0].length];
        int ans = 0;
        for( int r = 0; r<grid.length; r++){
            for(int c = 0 ; c < grid[0].length; c++){
                ans = Math.max(ans,area(r,c));
            }
        }
        
        return ans;
    }
    
}
