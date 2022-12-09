1st Solution Brute Force
void setZeroes(vector<vector<int>>& mat) {

       // T.C = O(r*c) + O(arr.size()) + O(r) + O(c)
       // S.C = O(n)

       //Creating a vector that keeps 0th element row and col index 

       vector<pair<int,int>>arr;

       int r = mat.size();
       int c = mat[0].size();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==0)
                {
                    arr.push_back({i,j});
                }
            }
        }

        for(auto it: arr)
        {
            int p = it.first;
            int q = it.second;

          //  arr.erase(arr.begin()+0);

            for(int i=0;i<c;i++)
            {
                mat[p][i]=0;
            }

            for(int i=0;i<r;i++)
            {
                mat[i][q]=0;
            }
        }

    }

2nd Solution 
void setZeroes(vector<vector<int>>& mat) {
        
        int r = mat.size();
        int c = mat[0].size();
        
        vector<int>row(r,1);
        vector<int>col(c,1);

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        
        for(int i=0;i<r;i++)
        {
           for(int j=0;j<c;j++)
           {
               if(row[i]==0 || col[j]==0)
               {
                   mat[i][j]=0;
               }
           }
        }

    }

3rd Solution Most Optimized
void setZeroes(vector<vector<int>>& mat) {
   
        // T.C = O(r) + O(c) + O(r*c)
        // S.C = O(1)
        
        int n = mat.size();
        int m = mat[0].size();
        
        bool row0 = false;
        bool col0 = false;
        
        for(int i=0;i<n;i++)if (mat[i][0] == 0) col0 = true;
        for(int j=0;j<m;j++)if (mat[0][j] == 0) row0 = true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<n;i++)
        {
            if(mat[i][0]==0)
            {
                for(int j=0;j<m;j++)
                {
                    mat[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<m;i++)
        {
            if(mat[0][i]==0)
            {
                for(int j=0;j<n;j++)
                {
                    mat[j][i] = 0;
                }
            }
        }
        
        if(row0)
        {
            for(int i=0;i<m;i++)mat[0][i]=0;
        }
        
        if(col0)
        {
            for(int i=0;i<n;i++)mat[i][0] = 0;
        }   
        
}