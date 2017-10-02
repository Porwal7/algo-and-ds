#include<iostream>
#include<string>
#include<cstdlib>
#include<climits>
using namespace std;
string longestcommonsubstring(string s,string p){
	int m=s.length();
	int n=p.length();
	string t;
	int dp[m][n];
	int max=INT_MIN;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0||j==0)
			 dp[i][j]=(s[i]==p[j])?1:0;
			 else{
			 	if(s[i]==p[j])
			 	dp[i][j]=dp[i-1][j-1]+1;
			 	else{
			 		dp[i][j]=0;
				 }
				 if(max<dp[i][j]){
				 	max=dp[i][j];
				 	t=s.substr((i-max+1),i+1);
				 }
			 }
		}
	}
	return t;
}
int main(){
string s,p;
cin>>s>>p;
cout<<longestcommonsubstring( s, p);
return 0;	
}
