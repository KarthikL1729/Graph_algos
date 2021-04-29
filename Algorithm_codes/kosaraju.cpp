#include <bits/stdc++.h>
using namespace std;

//Kosaraju's alogrithm works on the principle that reversing the edges of an SCC still doesn't change the fact that it is an SCC

//ZERO BASED INDEXING!!!!!!!!!!!!!!!!

void dfs(int i, vector<vector<int>> &gr, bool *vs, stack<int>& s) //dfs with stack pushing
{
    vs[i] = 1;
    for(int j = 0; j < gr[i].size(); j++)
        if(!vs[gr[i][j]])
            dfs(gr[i][j], gr, vs, s);

    s.push(i);  //Pushing into stack for checking with transpose
}

void dfsprint(int u, vector<vector<int>> &gr, bool *vst)  //Standard dfs
{
	vst[u] = true;
	cout << u << " ";
	for (auto it : gr[u])
	{
		if (!vst[it])
		{
			dfsprint(it, gr, vst);
		}
	}
}

int kosaraju(vector<vector<int>> &gr, int n)
{
    stack<int> s;
    bool vs[n] = {0};
    for(int i = 0; i < n; i++)
        if(!vs[i])
            dfs(i, gr, vs, s);    //Traversing the graph and pushing everything into the stack in dfs order

    vector<vector<int>> transpose(n);
    for(int i = 0; i < n; i++)
    {
        vs[i] = 0;  //Reinitialise vs for next dfs run
        for(int j = 0; j < gr[i].size(); j++)
            transpose[gr[i][j]].push_back(i); //Reversing all edges to find transpose
    }

    int count = 0;
    cout<<"SCCs:\n";
    while(!s.empty())
    {
        int root = s.top(); //Popping the first root element, considered to be part of an SCC
        s.pop();
        //cout<<"s"<<root<<" ";
        if(!vs[root])
        {
            dfsprint(root, transpose, vs);  //Finds and prints all the nodes of the corresponding SCC, cannot continue to the next SCC because of the reversal
            count++;
            cout<<endl;
        }
    }
    
    cout<<"Number of SCCs: "<<count<<endl;

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
    vector<vector<int>> gr(n);
    cout<<"Edges in Start, end format (directed)\n";
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b); //distance first, end point second in make pair
        //gr[b].push_back(make_pair(c, a)); //comment to make it directed
    }

    kosaraju(gr, n);

    return 0;
}