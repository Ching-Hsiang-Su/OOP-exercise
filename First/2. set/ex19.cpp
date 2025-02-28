#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    int count,c1,c2;
    cin >> count >> c1 >> c2;

    for (int i = 0;i < count;i++){
        int temp;
        cin >> temp;
        if(temp < c2 && temp >= c1)
            s.insert(temp);
    }
    cout << s.size() << endl;
}