#include<bits/stdc++.h>
using namespace std;

class LRUCache{

list<int>cache;
unordered_map<int, list<int>::iterator>cache_map;
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

if(cache_map.find(x) == cache_map.end()){

    if(cache.size() == csize){

        int last = cache.back();
        cache.pop_back();
        cache_map.erase(last);
    }
}
else{
    cache.erase(cache_map[x]);
}
cache.push_front(x);
cache_map[x] = cache.begin();


}
void LRUCache :: display()
{

    for(auto it = cache.begin(); it!= cache.end(); it++){

        cout<<(*it)<<" ";

    }
    cout<<endl;
}

int main(){


LRUCache c(5);
c.refer(10);
c.refer(20);
c.refer(30);
c.refer(40);
c.refer(50);
c.refer(60);
c.display();

return 0;
}
