#include<iostream>
#include<map>

using namespace std;
int main(){
    map<string, int> studs = 
    {
        {"name1",10},
        {"name2",8},
        {"name3",5},
        {"name4",9}
    }; 
    //studs.insert(make_pair("name20".6));
    studs.insert(pair<string, int>("name20,6"));
    studs["name20"] = 4;
    cout<<studs["name20"] << endl;
    
}