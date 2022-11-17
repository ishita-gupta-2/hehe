#include<bits/stdc++.h>
using namespace std;

void parent_fill(vector<int> parents[], vector<int> adj[], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(auto it: adj[i])
            parents[it].push_back(i);
    }
}

set<int> intersection(vector<int> arr, vector<int> D[], int n)
{
    set<int> ans;
    for(auto i: D[arr[0]])
    {
        bool found = true;
        for(auto it: arr)
        {
            if(!count(D[it].begin(), D[it].end(), i))
            {
                found = false;
                break;
            }
        }
        if(found)   ans.insert(i);
    }
    return ans;
}

void D_fill(vector<int> D[], vector<int> adj[], vector<int> parents[], int n)
{
    D[1] = {1};
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            D[i].push_back(j);
    }
    
    bool change = true;
    while(change)
    {
        change = false;
        for(int i=2; i<=n; i++)
        {
            set<int> intersection_parent = intersection(parents[i], D, n);
            intersection_parent.insert(i);
            vector<int> temp;
            for(auto it: intersection_parent)
                temp.push_back(it);
            if(temp != D[i])
                change = true;
            D[i] = temp;
        }
    }
}

int main()
{
    int n; cin>>n;
    
    // Take graph as input
    vector<int> adj[n+1];
    while(1)
    {
        int x; cin>>x;
        if(x==-1)
            break;
        int y; cin>>y;
        adj[x].push_back(y);
    }
    
    // Initialize
    vector<int> D[n+1];
    
    // Pre-compute parents
    vector<int> parents[n+1];
    parent_fill(parents, adj, n);
    
    for(int i=1; i<=n; i++)
    {
        cout<<i<<": ";
        for(auto it: parents[i])
            cout<<it<<", ";
        cout<<endl;
    }
    
    // Pre-compute all D
    D_fill(D, adj, parents, n);
    
    for(int i=1; i<=n; i++)
    {
        cout<<i<<": ";
        for(auto it: D[i])
            cout<<it<<", ";
        cout<<endl;
    }
    return 0;
}


// 10
// 1 2
// 1 3
// 2 3
// 3 4
// 4 3
// 4 5
// 4 6
// 5 7
// 6 7
// 7 4
// 7 8
// 8 3
// 8 9
// 8 10
// 9 1
// 10 7
// -1

