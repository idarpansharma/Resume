class Solution {
public:
   vector<vector<int>> a;

   bool is_poss(int ii, int jj) {
       int n = a.size();
       for (int i = 0; i < ii; i++) 
           if (a[i][jj]) 
               return 0;

       int i = ii, j = jj;
       while (i >= 0 && j >= 0) {
           if (a[i][j]) 
               return 0;
           i--;
           j--;
       }
       
       i = ii, j = jj;
       while (i >= 0 && j < n) {
           if (a[i][j]) 
               return 0;
           i--;
           j++;
       }
       return 1;
   }

   int fn(int n, int i, int j) {
       if (n == 0) 
           return 1;
       if (i >= a.size() || j >= a[0].size()) 
           return 0;

       int ans = 0;
       if (is_poss(i, j)) {
           a[i][j] = 1;
           ans += fn(n - 1, i + 1, 0);
           a[i][j] = 0;
       }
       ans += fn(n, i, j + 1); 
       return ans;
   }

   int totalNQueens(int n) {
       if (n == 1) 
           return 1;
       if (n < 4) 
           return 0;

       a.resize(n, vector<int>(n, 0));
       return fn(n, 0, 0);
   }
};