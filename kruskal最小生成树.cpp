#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int fa[maxn];
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void init() {
	for(int i=0; i<maxn; i++) {
		fa[i]=i;
	}
}
void baba(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
struct node{
	int u,v,w;
}e[maxn];
int cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	int n,m;
	init();
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e,e+m,cmp);
	int cnt=0,ans=0;
	cout<<"图的最小生成树:"<<endl;
	for(int i=0;i<m;i++){
		if(cnt==n-1)break;
		if(find(e[i].u)==find(e[i].v))continue;
		else{
			baba(e[i].u,e[i].v);
			cout<<"V"<<e[i].u<<"----V"<<e[i].v<<"="<<e[i].w<<endl;
			ans+=e[i].w;
			cnt++;
		}	
	}
	cout<<"最小生成树权值:"<<endl;	
	cout<<ans<<endl;
}
/*6 10
1 4 5
2 3 5
2 5 3
3 5 6
3 6 4
4 3 5
5 6 6
4 6 2
1 2 6
1 3 1
*/
