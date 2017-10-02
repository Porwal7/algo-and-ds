#include<iostream>
#include<vector>
using namespace std;
int n;
int ceil(vector<int>v,int *a,int l,int k){
	int start=0,end=l,mid;
	while(start<end){
		mid=(start+end)/2;
		if(v[a[mid]]<k&&v[a[mid+1]]>=k)
		return mid+1;
		else if(v[a[mid]]<k)
		start=mid+1;
		else
		end=mid-1;
	}
	return -1;
	
}
int *lis(vector<int>v){
	int *parent=new int[v.size()+1];
	int *t=new int[v.size()+1];
	n=v.size();
	fill(parent,parent+n,-1);
	int l=0;
	t[0]=0;
	for(int i=1;i<v.size();i++){
		if(v[t[0]]>v[i]){
				t[0]=i;
				cout<<t[0]<<"update at 0";
			}
		else if(v[t[l]]<v[i]){
		l++;
		t[l]=i;
		parent[t[l]]=t[l-1];
	}
		else{
		int index=ceil(v,t,l,v[i]);
		 t[index]=i , parent[t[index]]=t[index-1];
	}
}
	int k=t[l];
	n=l+1;
	int *lisk=new int[l+1];
	while(k!=-1){
		cout<<k<<" "<<v[k]<<" "<<l<<endl;
		lisk[l]=v[k];
		k=parent[k];
		l--;
	}
	for(int i=0;i<n;i++)
	cout<<lisk[i];
	return lisk;
}
int main(){
	int k;
	cin>>k;
	vector<int>v(k);
	for(int i=0;i<k;i++)
	cin>>v[i];
	int *a=lis(v);
	cout<<endl;
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
