#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    void dfs(vector<int>adjls[],vector<int>&visited,int i)
    {
        visited[i]=1;
        for(auto it:adjls[i])
        {
            if(visited[i]==0)
            {
                dfs(adjls,visited,it);
                visited[it]=1;
            }

        }
    }

    int numProvinces(vector<vector<int>>adj,int V)
    {
       vector<int>adjls[V];
       for(int i=0;i<V;i++)
       {
        for(int j=0;j<V;j++)
        {
            if(i!=j && adj[i][j]==1)
            {
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
       }

       vector<int>visited;
       int count=0;

       for(int i=0;i<V;i++ )
       {
          if(visited[i]==0)
          {
            dfs(adjls,visited,i);
           
          }
          count++;
       }

       return count;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,x;
        cin>>V;
        vector<vector<int>>adj;
        for(int i=0;i<V;i++)
        {
            vector<int>temp;
            for(int j=0;j<V;j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout<<ob.numProvinces(adj,V)<<endl;
    }

}