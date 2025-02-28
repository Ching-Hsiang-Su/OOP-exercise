#include<iostream>
#include<vector>

using namespace std;
int main(){
    int p,j;
    cin >> p >> j;
    vector<int>v1(p);
    vector<int>v2(j);
    for(int i = 0; i<p; i++)
        cin >> v1[i];
    for(int i = 0; i<j; i++)
        cin >> v2[i];

    int count = 0;
    vector<int>v1temp = v1;
    vector<int>v2temp = v2;


    while(v1.size() != 0 && v2.size() != 0){
        if(v1[0]>v2[0]){
            v1.push_back(v2[0]);
            v1.push_back(v1[0]);
            v1.erase(v1.begin());
            v2.erase(v2.begin());
        }
        else{
            v2.push_back(v1[0]);
            v2.push_back(v2[0]);
            v2.erase(v2.begin());
            v1.erase(v1.begin());
        }
        count++;
        if (v1 == v1temp || v2 == v2temp)
            break ;
        else if (count > 10000)
            break;

    }
        if(v1.size() == 0)
            cout << count << " " << "Jhon" << endl;
        else if(v2.size() == 0)
            cout << count << " " << "Peter" << endl;
        else 
            cout << "Both losers" << endl;
        
}