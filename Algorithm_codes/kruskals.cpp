#include <bits/stdc++.h>
using namespace std;

//ZERO BASED INDEXING!!!!!!!!!!!!!!!!

typedef pair<int, int> pi;

struct Edge
{
    int u, v, w;
};

bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}
//DSU stuff

vector<int> parent, r;

void dsu_init(int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        r[i] = 0;
    }
}

int find_root(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_root(parent[v]);
}

void unite(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    if (a != b)
    {
        if (r[a] < r[b])
            parent[a] = b;
        else
        {
            parent[b] = a;
            if (r[a] == r[b])
                r[a]++;
        }
    }
}

//DSU's are basically used to ensure that we don't select edges that result in a cycle

int kruskal(vector<Edge> edge, int m, int n)
{
    int res = 0, c = 0;
    vector<Edge> tr;
    for (int i = 0; c < n - 1 && i < m; i++)
    {
        if (find_root(edge[i].u) != find_root(edge[i].v))   //Ensuring that we do't choose an edge which will form a cycle
        {
            c++;
            res += edge[i].w;
            tr.push_back(edge[i]);
            unite(edge[i].u, edge[i].v);    
        }
    }

    cout << "Edges in the MST:\n";
    for (int i = 0; i < n - 1; i++)
        cout << tr[i].u << "--" << tr[i].v << "  "
             << "Cost:" << tr[i].w << endl;
    cout << "Total cost = " << res << endl;
    return 0;
}

int main()
{
    int n, m;
    cout << "Number of nodes and edges?\n";
    cin >> n >> m;
    parent.resize(n);
    r.resize(n);
    dsu_init(n);
    vector<Edge> edge(m);
    cout << "Edges in Start, end, dist format (undirected)\n";
    for (int i = 0; i < m; ++i)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    sort(edge.begin(), edge.end(), cmp);
    kruskal(edge, m, n);
}
