#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
 set<char> st;
 for(auto &c : s){
    st.insert(c);
 }
 if(st.size()&1){
    cout<<"IGNORE HIM!"<<endl;
 }
 else{
    cout<<"CHAT WITH HER!"<<endl;
 }
}