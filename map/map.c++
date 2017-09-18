#include <iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;


int main()
{
    int array[]={1,2,3,4,3,3,3,5,4,9,5,5};
    int size = sizeof(array)/sizeof(array[0]);
    
    set<int> s;
    for(int i = 0; i < size; i++){
	s.insert(array[i]);
	
    }

    for(auto val : s){
	cout<<val<<" ";
    }
    cout<<endl;

    unordered_set<int> us;
    for(int i = 0; i < size; i++){
	us.insert(array[i]);
	
    }

    for(auto val : us){
	cout<<val<<" ";
    }
    cout<<endl;

    map<int, int> m;
    for(int i = 0; i < size; i++){
	m[i] = (array[i]);
	
    }

    for(auto val : m){
	cout<<val.first<<": "<<val.second<<" ";
    }
    cout<<endl;

    unordered_map<int, int> um;
    for(int i = 0; i < size; i++){
	um[i] = (array[i]);
	
    }

    for(auto val : um){
	cout<<val.first<<": "<<val.second<<" ";
    }
    cout<<endl;
    return 0;
}
