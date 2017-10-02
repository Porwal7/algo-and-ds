#include<iostream>
#include<string>
#include<climits>
using namespace std;
int min(int a,int b){
	return (a<b)?a:b;
}
string mancherlongestpalin(string s){
	string t="^";
	int n=s.length();
	for(int i=0;i<n;i++)
	t+="#"+s.substr(i,1);
	t+="#$";
	int c=0;
	int r=0;
	cout<<t<<endl;
	int *p=new int[t.length()];
	for(int i=1;i<t.length();i++){
		int mirror=2*c-i;
		p[i]=(i<r)?min(r-i,p[mirror]):0;
		while(t[p[i]+1+i]==t[i-p[i]-1])
		p[i]++;
		if(i+p[i]>r){
			c=i;
			r=i+p[i];
		}
		
	}
	int max=-1;
	for(int i=1;i<t.length()-1;i++)
	if(p[i]>max){
		cout<<"i="<<i<<" p[i]="<<p[i]<<" max="<<max<<endl;
	max=p[i];
	c=i;
}
cout<<(c-max-1)/2<<max;
	return s.substr((c-max-1)/2,max);
}
int main(){
	string s;
	cin>>s;
	cout<<mancherlongestpalin(s);
	return 0;
}
