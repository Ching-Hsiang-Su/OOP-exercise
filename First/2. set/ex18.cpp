#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    int count;
    cin >> count;
    for (int i = 0;i < count;i++){
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size() << endl;
}