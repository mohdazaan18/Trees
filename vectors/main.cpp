#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    //vector<int> *v = new vector<int>();
    /*for(int i = 0;i<100;i++){
        cout<<"cap : "<<v.capacity()<<endl;
        cout<<"size : "<<v.size()<<endl;
        v.push_back(i+1);
    }*/

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v[1] = 900; // dont use [] for insertion
    v.push_back(40);
    v.pop_back();
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    cout<<v.at(1)<<endl;



    return 0;
}
