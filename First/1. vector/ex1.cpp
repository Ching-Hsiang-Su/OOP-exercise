#include <iostream>
#include <vector>

using namespace std;
int main(){
    int count1,count2;
    cin >> count1 >> count2;
    
    vector<int>v(count1);
    
    for(int i = 0; i<count1; i++)
        cin >> v[i];
    for(int i = 0; i<count2; i++){
        int removeIndex;
        cin >> removeIndex;
        v.erase(v.begin()+removeIndex-1);
    }
    for (int i = 0 ;i < v.size()-1 ;i++)
        cout << v[i] << " ";
    cout << *v.rbegin();
    
    return 0;
}