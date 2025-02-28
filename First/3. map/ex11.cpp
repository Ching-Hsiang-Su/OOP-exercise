#include<iostream>
#include<map>
#include<vector>

using namespace std;
int main(){
    int m;
    cin >> m;
    vector<string> v;
    map<string , int>words;
    for (int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
        if (words.find(temp) != words.end())
            words[temp]++;
        else 
            words.insert(make_pair(temp,1));
    }
    int max = words[v[0]];
    int word_index = 0;
    for(int i = 0; i < m ;i++){
        if(words[v[i]] > max){
            max = words[v[i]];
            word_index = i;
        }
    }
    cout << v[word_index] << endl;
}