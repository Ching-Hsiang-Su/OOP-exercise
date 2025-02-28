#include<iostream>
#include<set>

using namespace std;
int main(){
    set<int> s;
    int c1,c2;
    cin >> c1 >> c2;

    for (int i = 0;i < c1;i++){
        for (int j = 0; j< c2;j++){
            int temp;
            cin >> temp;
            if ((i==0) || (i==c1-1) || (j==0) || (j==c2-1)){
                s.insert(temp);
            }
        }
    }
    cout << s.size() << endl;
}