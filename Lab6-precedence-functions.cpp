#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> graph[], int &ans, int &maxi, int &k)
{
    ans++;
    if(maxi<ans)
    {
        maxi = ans;
        k = node;
    }
    for(auto it : graph[node])
    {
        dfs(it,graph,ans,maxi,k);
    }
    ans--;
}

int solve(vector<int> graph[], int node)
{
    int n = 14;
    int ans=0,maxi=0,k=0;
    dfs(node,graph,ans,maxi,k);
    return maxi-1;
}

int main()
{
    vector<vector<int>> v = {{1,1,-1,-1,-1,-1,1},
                             {1,1,-1,-1,-1,-1,1},
                             {1,1,1,1,-1,-1,1},
                             {1,1,1,1,-1,-1,1},
                             {1,1,1,1,-1,-1,1},
                             {1,1,1,1,1,0,1},
                             {-1,1,-1,-1,-1,-1,0}};
    vector<int> adj[14];
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j] == 1)
            {  adj[i].push_back(j+7); }
            else if(adj[i][j] == -1)
            {  adj[j+7].push_back(i); }
        }
    }

    cout<<"\nGRAPH --> ";
    for(int i=0;i<14;i++)
    {
        cout<<endl<<i<<" --> ";
        for(auto &x : adj[i])
        cout<<x<<" ";
    }

    cout<<"\n\nLINEAR DIMENSIONAL TABLE --> \n";
    cout<<"+ - * / ^ id $\n";
    //linear matrix
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(i==0)
            cout<<solve(adj,j)<<" ";
            else
            cout<<solve(adj,j+7)<<" ";
        }
        cout<<endl;
    }
    return 0;
}