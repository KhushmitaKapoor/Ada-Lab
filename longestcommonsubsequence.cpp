#include<iostream>
#include<vector>
using namespace std;
string LCS(string a,string b){
vector<vector<int> >ans(a.length()+1,vector<int>(b.length()+1,0));
vector<vector<char> >dir(a.length()+1,vector<char>(b.length()+1));
for(int i=1;i<=a.length();i++){
for(int j=1;j<=b.length();j++){
if(a[i-1]==b[j-1]){
ans[i][j]=ans[i-1][j-1]+1;
dir[i][j]='d';
}
else{
if(ans[i][j-1]>ans[i-1][j]){
dir[i][j]='l';
ans[i][j]=ans[i][j-1];
}
else{
dir[i][j]='u';
ans[i][j]=ans[i-1][j];
}
}
}
}
cout<<ans[a.length()][b.length()]<<endl;
int i=a.length(),j=b.length();
string s;
while(i>0&&j>0){
// cout<<dir[i][j]<<" ";
if(dir[i][j]=='d'){
s.push_back(a[i-1]);
i--;j--;
}
else if(dir[i][j]=='u')
i--;
else if(dir[i][j]=='l')
j--;
}
string anss;
for(int i=s.length()-1;i>=0;i--){
anss.push_back(s[i]);
}
return anss;
}
int main(){
string a,b;
cout << "string1: ";
cin>>a;
cout << "string2: ";
cin >> b;
cout<<"Longestcommon subsequence: "<<LCS(a,b)<<endl;
}






