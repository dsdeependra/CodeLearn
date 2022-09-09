#include<iostream>>
#include<cstring>
#include<map>
#include<set>

using namespace std;

bool isisomorphic(string& str1, string& str2){
    if(str1.length() !=str2.length()){
        return false;
    }
    map<char,char>m1;
    map<char,char>m2;

    for(int i=0;i<=str1.length();i++){
        
        if(m1.find(str1[i]) == m1.end()){
            //not there so insert
            m1[str1[i]] = str2[i];            
        }else{
            if(m1[str1[i]] != str2[i]){
                return false;
            }
        }
        if(m2.find(str2[i]) == m2.end()){
            m2[str2[i]] = str1[i];
        }else{
            if(m2[str2[i]] != str1[i]){
                return false;
            }
        }
        cout<<m1[str1[i]]<<"   "<<str2[i]<<endl;
        cout<<m2[str2[i]]<<"   "<<str1[i]<<endl;
        cout<<"**********"<<endl;
        //  else if(m1[str1[i]] == str2[i] && m2[str2[i]] ==str1[i] ){
        //     return true;
        // }
    }
    return true;
}

bool isomorphicSet(string& str1, string& str2){
    map<char,char>m;
    set<char>s;
     if(str1.length() !=str2.length()){
        return false;
    }
    for(int i=0;i<str1.length();i++){
        if(m.find(str1[i]) ==m.end() && s.find(str2[i]) == s.end()){
            m[str1[i]] = str2[i];
            s.insert(str2[i]);
        }
        else if(m.find(str1[i]) ==m.end() && s.find(str2[i]) != s.end()){
            return false;
        }
        else{
            if(m[str1[i]] != str2[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    string str1 = "for";
    string str2 = "baa";
    if(!isomorphicSet(str1,str2)){
        cout<<"Not isomorphic"<<endl;
    }
    else{
        cout<<"Isomorphic"<<endl;
    }
    return 0;
}