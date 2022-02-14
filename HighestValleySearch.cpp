#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool readFile(vector<int>&x, const string fileName);
bool condMaxSearch(const vector<int>&x,int &max,int &ind);
bool condMaxSearchFromFile(vector<int>&x, int &max, const string fileName);

bool readFile(vector<int>&x, const string fileName){
    fstream f(fileName);
    if(f.fail()){
        return false;
    }
    int e;
    x.clear();
    while(f>>e){
        x.push_back(e);
    }
    f.close();
    return true;
}

bool condMaxSearch(const vector<int>&x,int &max,int &ind){
    bool L = false;
    for( int i = 1; i<int(x.size()) - 1; i++){
        if(L&&(x[i-1]>=x[i]&&x[i]<=x[i+1])){
            if(max<x[i]){
                max = x[i];
                ind=i;
            }
        }
        else if( !L &&(x[i-1]>=x[i]&&x[i]<=x[i+1])){
            L = true;
            max = x[i];
            ind = i;
        }
    }
    return L;

}
//Second Approach
bool condMaxSearchFromFile(vector<int>&x, int &max, const string fileName){

    fstream f(fileName);
    bool L = false;
    int before;
    int current;
    int after;
    f>>before;
    f>>current;
    f>>after;
    while(!f.fail()){

        if(L&&(before>=current&&current<=after)){
            if(max<current){
                max = current;
            }
        }
        else if( !L &&(before>=current&&current<=after)){
            L = true;
            max = current;
        }
        before=current;
        current=after;
        f>>after;



    }
    f.close();
    return L;
}




int main()
{
    vector<int>x;
    string fileName;
    cout<<"Please enter a filename: "<<endl;
    cin>>fileName;
    if(readFile(x,fileName)){
        int max;
        int ind;
        if(condMaxSearch(x,max,ind)){
            cout<<"The highest valley is "<<max<<endl;
        }
        else{
            cout<<"No valley matching the search criteria"<<endl;
        }
        cout<<"----Second FromFile Approach----"<<endl;
        if(condMaxSearchFromFile(x,max,fileName)){
            cout<<"THe highest valley is "<<max<<endl;
        }
        else{
            cout<<"No valley matching the criteria"<<endl;
        }


    }else{
        cout<<"The file doesn't exist!"<<endl;
    }


    return 0;
}
