class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int colors,int org){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=org || image[sr][sc]==colors) return;
        image[sr][sc]=colors;
        dfs(image,sr+1,sc,colors,org);
        dfs(image,sr-1,sc,colors,org);
        dfs(image,sr,sc+1,colors,org);
        dfs(image,sr,sc-1,colors,org);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};