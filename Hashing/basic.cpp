#include<iostream>
using namespace std;
/*
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Precomputing hash values
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]] +=1;
    }


    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;

        // Fetch
        cout<<hash[num]<<endl;
    }
    return 0;

    

}
*/


#include<map>
#include<unordered_map>

int main(){

    //CREATION
    unordered_map<string,int> m;

    //INSERTION

    //1 Way
    pair<string,int> p = make_pair("Ansh",3);
    m.insert(p);

    //2 Way
    pair<string,int> p2("Nikhil",2);
    m.insert(p2);

    //3 Way
    m["buddy"] = 1;
    // Updating value
    m["buddy"] = 2;

    //SEARCHING
    cout<<m["Ansh"]<<endl; //O(1) average case time complexity
    cout<<m.at("Nikhil")<<endl;
    //cout<<m.at("Lodi")<<endl;   //Shows this error: terminate called after throwing an instance of 'std::out_of_range'
                                // what():  unordered_map::at
    cout<<m["Soham"]<<endl;      //Creates a new key "Lodi" with value 0

    //Size
    cout<<m.size()<<endl;

    //Count
    cout<<m.count("Ansh")<<endl; //1

    //erase
    m.erase("Soham");
    cout<<m.size()<<endl;  //3

    //Iterators
    unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout<< it->first <<" "<< it->second << endl;
        it++;
    }


    return 0;
}