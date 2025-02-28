//
//  main.cpp
//  oop course
//
//  Created by 蘇靖翔 on 2023/2/22.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    v.insert(v.begin() + 2,0);
    v.erase(v.begin()+3);
    
    for(int i = 0;i < v.size();i++)
        cout << v[i]<< " ";
    cout << endl;
    for (int el : v)
        cout << el << " ";
    cout << endl;
    return 0;
}