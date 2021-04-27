#include <bits/stdc++.h>
using namespace std;

//ZERO BASED INDEXING!!!!!!!!!!!!!!!!

typedef pair<int, int> pi;

int *dijkstra(vector<vector<pi>> gr, int n, int root)
{
    int dist[n];
    bool vs[n];
    for(int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        vs[i] = 0;
    }
    dist[root] = 0;

    priority_queue <pi, vector<pi>, greater<pi>> pq;
    pq.push(make_pair(0, root));
    while(pq.size())
    {
        int ind = pq.top().second;
        vs[ind] = 1;
        if(dist[ind] < pq.top().first)
        {
            pq.pop();
            continue;
        }
        pq.pop();
        for(int i = 0; i < gr[ind].size(); i++)
        {
            if(!vs[gr[ind][i].second])
            {
                int nd = dist[ind] + gr[ind][i].first;
                if(nd < dist[gr[ind][i].second])
                {
                    dist[gr[ind][i].second] = nd;
                    pq.push(make_pair(nd, gr[ind][i].second));
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout<<i<<" "<<dist[i]<<endl;
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
        gr[a].push_back(make_pair(c, b));
        gr[b].push_back(make_pair(c, a)); //comment to make it directed
    }
    int root;
    cout<<"Root?\n";
    cin>>root;
    dijkstra(gr, n, root);
    return 0;
}
