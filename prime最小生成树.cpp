#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int vis[maxn];
map<int,int>mp[maxn];
vector<int>v;
int n,m;
int prime(){
	int ans=0;
	v.push_back(1);
	vis[1]=1;
	int cnt=0;
	while(cnt<n-1){
		int minn=1e7+10,U,V;
		for(int i=0;i<v.size();i++){
			for(int j=1;j<=m;j++){
				if(!vis[j]&&mp[v[i]][j]<minn){
					minn=mp[v[i]][j];
					U=v[i];
					V=j;
				}
			}
		}
		cout<<"V"<<U<<"----V"<<V<<"="<<minn<<endl;
		vis[V]=1;
		v.push_back(V);
		cnt++;
		ans+=minn;
	}
	cout<<"最小生成树权值:"<<endl;	
	cout<<ans<<endl;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			mp[i][j]=1e7+10;
		}
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	cout<<"图的最小生成树:"<<endl;
	prime();
}
