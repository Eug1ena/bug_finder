#include <iostream>
#include <random>
#include <set>
#include <unordered_set>
using namespace std;

namespace rnd{

using lint = long long;

random_device seed_gen;
default_random_engine engine(seed_gen());

template<class T>
T choose(T n){ // [0, n)
    if(n <= 0){
        cerr << "ERROR in rnd::choose(): n=" << n << endl;
    }
    uniform_int_distribution<T> dist(0, n - 1);
    return dist(engine);
}
template<class T>
T choose(T l, T r){ // [l, r]
    if(l > r){
        cerr << "ERROR in rnd::choose(): l=" << l << ", r=" << r << endl;
    }
    return choose(r - l + 1) + l;
}

template<class T>
vector<T> array(T n, int k){ // [0, n)
    if(n < 0 || k < 0 || k > n){
        cerr << "ERROR in rnd::array(): n=" << n << ", k=" << k << endl;
    }
    
    vector<T> ret;
    if(n / 2 < k){
        vector<T> all(n);
        iota(all.begin(), all.end(), 0);
        shuffle(all.begin(), all.end(), engine);
        
        for(int i = 0; i < k; i++){
            ret.push_back(all[i]);
        }
    }else{
        unordered_set<T> ans;
        while(ans.size() < k){
            ans.insert(choose(n));
        }
        
        for(T i: ans){
            ret.push_back(i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

vector<pair<int, int>> tree(int n){
    if(n < 1){
        cerr << "ERROR in rnd::tree(): n=" << n << endl;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    shuffle(v.begin(), v.end(), engine);
    
    vector<pair<int, int>> ret;
    for(int i = 1; i < n; i++){
        int p = choose(i);
        ret.push_back({v[p], v[i]});
    }
    return ret;
}

vector<pair<int, int>> graph(int n, int m){
    if(n < 0 || m < 0 || m > (lint)n * (n - 1) / 2){
        cerr << "ERROR in rnd::graph(): n=" << n << ", m=" << m << endl;
    }
    vector<lint> choice = array((lint)n * (n - 1) / 2, m);
    sort(choice.begin(), choice.end());
    
    vector<pair<int, int>> ret;
    lint sum = 0;
    int v = 0;
    for(lint i: choice){
        while(i >= sum + (n - v - 1)){
            sum += n - v - 1;
            v++;
        }
        ret.push_back({int(i - sum) + v + 1, v});
    }
    return ret;
}

vector<pair<int, int>> connected_graph(int n, int m){
    if(n < 0 || m < n - 1 || m > (lint)n * (n - 1) / 2){
        cerr << "ERROR in rnd::connected_graph(): n=" << n << ", m=" << m << endl;
    }

    vector<pair<int, int>> ret;
    vector<lint> bias(n);
    bias[0] = 0;
    for(int i = 0; i < n - 1; i++){
        bias[i + 1] = (n - i - 1) + bias[i];
    }

    auto base_tree = tree(n);
    vector<lint> tree_edges;
    for(auto e: base_tree){
        int u = e.first, v = e.second;
        if(u > v) swap(u, v);
        
        tree_edges.push_back(bias[u] + (v - u - 1));
        ret.push_back({u, v});
    }
    sort(tree_edges.begin(), tree_edges.end());

    vector<lint> choice = array((lint)n * (n - 1) / 2 - (n - 1), m - (n - 1));
    sort(choice.begin(), choice.end());

    lint sum = 0;
    int v = 0, ptr = 0;
    for(lint i: choice){
        while(ptr < n - 1 && tree_edges[ptr] <= i + ptr){
            ptr++;
        }
        lint x = i + ptr;
        while(x >= sum + (n - v - 1)){
            sum += n - v - 1;
            v++;
        }
        ret.push_back({int(x - sum) + v + 1, v});
    }
    return ret;
}

}
