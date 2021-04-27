#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	struct node* left,*right;
	node(int value)
	{
		val=value;
		left=nullptr;
		right=nullptr;
	}

}*root=nullptr;
node* insert(node *p,int value)
{
	if(p==nullptr)
	{
		p=new node(value);
		return p;
	}
	else if(p->val > value)
		p->left=insert(p->left,value);
	else if(p->val < value)
		p->right=insert(p->right,value);
	return p;
}
void inorder(node *p)
{
	if(p == nullptr)
		return;
	inorder(p->left);
	cout<<p->val<<" ";
	inorder(p->right);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 	int n;cin>>n;
 	vector<int>a(n);
 	for (int i = 0; i < n; ++i)
 	{
 		cin>>a[i];
 		root=insert(root,a[i]);
 	}
 	inorder(root);
 	cout<<endl;

    return 0;
}