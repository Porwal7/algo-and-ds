#include<iostream>
using namespace  std;
int getmax(int a[],int n){
	int max=-1;
	for(int i=0;i<n;i++){
		if(max<a[i])
		max=a[i];
	}
	return max;
}
void countsort(int a[],int n,int exp){
int i,o[n];
int b[10]={0};
for(i=0;i<n;i++){
	b[(a[i]/exp)%10]++;
} 
for(i=1;i<10;i++)
b[i]+=b[i-1];
for(i=0;i<n;i++){
o[b[(a[i]/exp)%10]-1]=a[i];b[(a[i]/exp)%10]--;}
for(i=0;i<n;i++)
a[i]=o[i];
}
void radix(int a[],int n){
	int exp,m;
     m=getmax(a,n);	
	for(exp=1;m/exp>0;exp=exp*10)
	countsort(a,n,exp);
}
int main(){
	int a[100],n,i;
	cout<<"enter the number of term ";
	cin>>n;
	cout<<"\nenter number";
	for(i=0;i<n;i++)
	cin>>a[i];
	radix(a,n);
	for(i=0;i<n;i++)
	cout<<endl<<a[i];
	return 0;
}
