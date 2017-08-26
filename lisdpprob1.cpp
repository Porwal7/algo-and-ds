#include<iostream>
#include<cstring>
using namespace std;
int size;
int cidx(int a[],int t[],int end ,int s){
	int mid,start=0,len=end;
	while(start<=end){
		mid=(start+end)/2;
		if(mid<len && a[t[mid]]<s&&s<=a[t[mid+1]]) return mid+1;
		else if(a[t[mid]]<s) start=mid+1;
		else end=mid-1;
		}
	
	return 1;
}
int *lis(int a[],int k){
	int n=k;
	int *t=new int[n];
	int *r=new int[n];
	int len=0;
//	cout<<"n="<<n<<" ";
	memset(r,-1,sizeof (r));
t[0]=0;
	for(int i=1;i<n;i++){
		//	cout<<"2 "<<a[0];
		if(a[t[0]]>a[i]) t[0]=i;
			
		else if(a[t[len]]<a[i]) {
		len++;
		t[len]=i;
		r[t[len]]=t[len-1];
	//	cout<<len<<"=len ";
	//	cout<<"21";
	}
		else {int index=cidx(a,t,len,a[i]) ;
		t[index]=i ;
		r[t[index]]=t[index-1];
	//cout<<"23";	
		}
	//	cout<<"2";
		   
	}
	size=len;
	cout<<true;
int	*ans=new int[len];
	int index=t[len];
	while(index!=-1){
		ans[len]=a[index];
		index=r[index];
		//cout<<len<<" ";
		len--;
	}
	return ans;
}
int main(){
	int t,j;
	cin>>t;
	int *a=new int[t];
	for(int i=0;i<t;i++) cin>>a[i];
	int n,q;
	cin>>n>>q;

int *	ans=lis(a,t);
	int len=size;
	cout<<true;
//	for(int i=0;i<len;i++)
//	cout<<ans[i]<< " ans";
cout<<"len="<<len<<endl;
	if(q==0)
	for(int i=0;i<n && i<len;i++)
	cout<<ans[i]<<" ";
	else if(q==1)
	for(int i=len-n+1,j=0;j<n&&i<=len;i++,j++)
	cout<<ans[i]<<" ";
	else {
	        for(int i=len-n+1, j=0;j<n&&i<=len;i++,j++) cout<<ans[i]<<" "<<i<<" a";
	        cout<<endl;
	        for(int i=0;i<n && i<len;i++)
             	cout<<ans[i]<<" "<<i<<" a";
             }
             return 0;
	
}
