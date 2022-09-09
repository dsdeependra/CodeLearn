#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache{
    list<int> dq;
    unordered_map<int, list<int>::iterator > ma;
    int csize;

    public:
        LRUCache(int);
        void refer(int);
        void display();
};

LRUCache :: LRUCache(int n){
    csize = n;
}

void LRUCache :: refer(int x){
    //if x is there in map or not
    if(ma.find(x) == ma.end()){
        //if queue id full
        if(dq.size() == csize){
            //remove element from back from dq  
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }

    dq.push_front(x);
    ma[x] = dq.begin();
}

void LRUCache :: display(){
    for(auto it = dq.begin(); it != dq.end(); ++it){
        cout<<*it<<" ";
    }
}

int main(){
    LRUCache ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}


