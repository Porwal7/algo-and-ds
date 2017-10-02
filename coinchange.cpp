#include<bits\stdc++.h>
using namespace std;
int min(int a,int b){
	return (a<b?a:b);
}
int a[1000001];
int cinneededdr(int coin[],int amount,int n){
	if(amount==0){
		return 0;
	}
	if(a[amount]!=-1)
	return a[amount];
	int min=INT_MAX;
	for(int j=0;j<n;j++){
		if(amount<coin[j])
		  continue;
		  int val=cinneededdr(coin,amount-coin[j],n);
		  cout<<"amount="<<amount<<" val="<<val<<endl;
		  if(min>val)
		  min=val;
		  
	}
a[amount]=(min==INT_MAX?min:min+1);
return a[amount];	
}
 int cinneededi(int  coin[],int amount ,int n){
 int *a=new  int[amount+1];
	a[0]=0;
	for(int i=1;i<=amount;i++){
		a[i]=INT_MAX;
	//	cout<<a[i];
		for(int j=0;j<n;j++){
		
			if(i>=coin[j]){
					 int small=a[i-coin[j]];
					 cout<<j<<" "<<small<<endl;
				a[i]=min(small+1,a[i]);
			
			}
		}
	
	}
		return a[amount];
}
	int main(){
		int coin[]={1,7,10};
		int k;
		cin>>k;
		cout<<cinneededi(coin,k,3)<<endl;
		a[0]=0;
	fill(a,a+k+1,-1);
		cout<<cinneededdr(coin,k,3);
		return 0;
	}
