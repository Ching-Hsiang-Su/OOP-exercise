#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(){
    set<int> s;
    string a;
    cin >> a;

    for (int i = 0;i<a.length();i++){
        int temp = a[i];
        if(a[i]=='0' || a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9' || a[i]==' ')
        s.insert(temp);
    } 
    if ((a.length()-s.size()<=2) && a.length()<=10)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

}