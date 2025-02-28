#include<iostream>
#include<map>
#include<set>

using namespace std;
int main(){
    string a;
    int count = 0 ;
    cin >> a;
    set<char>s;
    map<char , int>words;
    for (int i = 0; i < a.length(); i++){
        if (words.find(a[i]) != words.end())
            words[a[i]]++;
        else 
            words.insert(make_pair(a[i],1));
    }
    for(int i = 0; i<a.length();i++){
        if(words[a[i]]>2){
            s.insert(a[i]);
        }
    }
    cout << s.size() << endl;

}