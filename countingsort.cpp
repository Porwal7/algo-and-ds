#include<iostream>
using namespace std;
void countsort(int a[],int n ,int b[],int k){
	int c[k+1],i;
	for(i=0;i<k;i++)
	c[i]=0;
	cout<<"\nloop1 "<<"i    "<<"a[i]   "<<"  c[a[i]]";
	for(i=0;i<n;i++){
	c[a[i]]=c[a[i]]+1;
	cout<<"\n\t"<<i<<"    "<<a[i]<<"    "<<c[a[i]];
}
cout<<"\nloop2    "<<"i   "<<"c[i] ";
	for(i=1;i<=k;i++){
	c[i]=c[i]+c[i-1];
	cout<<"\n\t"<<i<<"    "<<c[i]<< "  "<<a[i];
}
cout<<"\nloop1  "<<"i    "<<"a[i]   "<<"c[a[i]]   "<<"b[c[a[i]]]";
	for(i=n-1;i>=0;i--){
		b[c[a[i]]-1]=a[i];
		
		cout<<"\n\t "<<i<<"    "<<a[i]<<"    "<<c[a[i]]<<"    "<<b[c[a[i]]-1];
		c[a[i]]=c[a[i]]-1;
	}
}
int main(){
	int a[10],n,i,k=0,b[10];
	cout<<"\nenter the number of term ";
	cin>>n;
	cout<<"\nenter the number to be sort ";
	for(i=0;i<n;i++){
	cin>>a[i];
	if(k<a[i])
	k=a[i];
}
    countsort(a,n,b,k);
	cout<<"Sorted order ";
	for(i=0;i<n;i++)
	cout<<" "<<b[i];
	return 0;
	
}
