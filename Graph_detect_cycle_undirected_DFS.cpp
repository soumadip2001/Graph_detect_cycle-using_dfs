#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cycle_util(int node,int parent, vector<int> adj[],vector<int> &vis)
{
	vis[node]=1;
	for(auto x:adj[node])
	{
		if(vis[x]==0)
		{
		    if(cycle_util(x,node,adj,vis))
				return true;
			else if(x!=parent)
				return true;
		}
	}
	return false;	
}
bool cycle(vector<int> adj[],int n)
{
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(cycle_util(i,-1,adj,vis))
				return true;
		
		}
	}	
	return false;
}
int main()
{
	int t=0;
	cin>>t;
	while(t--)
	{
		int n=0;
		cout<<"no of vertex  and edges ";
		cin>>n;
		vector<int> adj[n+1];
		cout<<"vertex and edges ";
		for(int i=0;i<=n;i++)
		{
			int u,v;
			cin>>u;
			cin>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(cycle(adj,n))
			cout<<"true";
		else
		 	cout<<"false";
	}
	return 0;
}
