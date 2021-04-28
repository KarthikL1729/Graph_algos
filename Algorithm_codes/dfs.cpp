#include <bits/stdc++.h>
using namespace std;
#define vb vector<bool>
void dfs(int u, vector<vector<int>> &gr, vb &vst)
{
	vst[u] = true;
	cout << u+1 << " ";
	for (auto it : gr[u])
	{
		if (!vst[it])
		{
			dfs(it, gr, vst);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> gr(n);
	vb vst(n);
	for (int i = 0; i < n; i++)
	{
		vst[i] = 0;
	}
	
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		gr[a].push_back(b);
		//gr[b].push_back(a);
	}

	dfs(0, gr, vst);
	cout<<endl;
	return 0;
}