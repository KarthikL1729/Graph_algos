#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 	int n,m;cin>>n>>m;
 	vector<vector<int>>gr(n);
 	for (int i = 0; i < m; ++i)
 	{
 		int a,b;cin>>a>>b;
 		a--;
 		b--;
 		gr[a].push_back(b);
 		//gr[b].push_back(a);
 	}
 	int root=0;
 	queue<int>que;
 	vector<bool>vst(n,false);
	vector<int>prev(n, -1);
	//vector<int>spath;
 	que.push(root);
 	vst[root]=true;
 	vector<int>level(n,0);
 	while(!que.empty())
 	{
 		int u=que.front();que.pop();
 		for(int i=0;i<gr[u].size();i++)
 		{
 			auto it=gr[u][i];
 			if(!vst[it])
 			{
				prev[it] = u; //Can be used to find shortest path between two nodes
 				level[it]=level[u]+1;
 				vst[it]=true;
 				que.push(it);
 			}
 		}
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		cout<<level[i]<<endl;
 	}

    return 0;
}