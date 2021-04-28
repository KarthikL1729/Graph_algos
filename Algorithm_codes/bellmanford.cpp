#include <bits/stdc++.h>
using namespace std;

//ZERO BASED INDEXING!!!!!!!!!!!!!!!!

typedef pair<int, int> pi;

int bellmanford(vector<vector<pi>> gr, int n, int root)
{
    int dist[n];
    for(int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[root] = 0;
    for(int i = 0; i < n - 1; i++) //First run to find shortest path (if exists)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < gr[j].size(); k++)
            {
                int nd = dist[j] + gr[j][k].first;
                if(nd < dist[gr[j][k].second])
                    dist[gr[j][k].second] = nd;
            }
        }
    }

    for(int i = 0; i < n - 1; i++) //Second run to find nodes in negative cycle
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < gr[j].size(); k++)
            {
                int nd = dist[j] + gr[j][k].first;
                if(nd < dist[gr[j][k].second])
                    dist[gr[j][k].second] = -INT_MAX;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }

    return 0;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int n, m;
    cout<<"Number of nodes and edges in that order?\n";
    cin >> n >> m;
    vector<vector<pi>> gr(n);
    cout<<"Edges in Start, end, dist format (undirected)\n";
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        gr[a].push_back(make_pair(c, b)); //distance first, end point second in make pair
        gr[b].push_back(make_pair(c, a)); //comment to make it directed
    }
    int root;
    cout<<"Root?\n";
    cin>>root;
    bellmanford(gr, n, root);
    cout<<"Nodes with -INT_MAX values for distance are the nodes that are part of a negative cycle.\n";
    return 0;
}