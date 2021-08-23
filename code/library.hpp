random_device rand_dev;
mt19937 rand_eng(rand_dev());

struct io_init {
    io_init() {
      cin.tie(nullptr); cout.tie(nullptr);
      std::ios::sync_with_stdio(false);
    }
} io_init;

template<class T>
vector<T> RandomChoice(T n, int k){ // [0, n)
    if(n < 0 || k < 0 || k > n){
        cerr << "ERROR in RandomChoice(): n=" << n << ", k=" << k << endl;
    }
    if(n / 2 < k){
        vector<T> all(n);
        iota(all.begin(), all.end(), 0);
        shuffle(all.begin(), all.end(), rand_eng);
        
        vector<T> ret;
        for(int i = 0; i < k; i++){
            ret.push_back(all[i]);
        }
        return ret;
    }else{
        set<T> ans;
        
        while(ans.size() < k){
            ans.insert(rand_dev() % n);
        }
        
        vector<T> ret;
        for(T i: ans){
            ret.push_back(i);
        }
        return ret;
    }
}

vector<int> MakeTree(int n){
    if(n < 1){
        cerr << "ERROR in MakeTree(): n=" << n << endl;
    }
    vector<int> ret(n);
    ret[0] = -1;
    for(int i = 1; i < n; i++){
        ret[i] = rand_dev() % i;
    }
    return ret;
}

vector<pair<int, int>> MakeGraph(int n, int m){
    if(n < 0 || m < 0 || m > n * (n - 1) / 2){
        cerr << "ERROR in MakeGraph(): n=" << n << ", m=" << m << endl;
    }
    vector<long long> choice = RandomChoice((long long)n * (n - 1) / 2, m);
    sort(choice.begin(), choice.end());
    
    vector<pair<int, int>> ret;
    long long sum = 0;
    int now = 0;
    for(auto i: choice){
        while(i - sum >= now){
            sum += now;
            now++;
        }
        int from = int(i - sum), to = now;
        ret.push_back({from, to});
    }
    return ret;
}

vector<pair<int, int>> MakeConnectedGraph(int n, int m){
    if(n < 0 || m < n - 1 || m > n * (n - 1) / 2){
        cerr << "ERROR in MakeConnectedGraph(): n=" << n << ", m=" << m << endl;
    }
    
    vector<pair<int, int>> ret;
    
    auto tree = MakeTree(n);
    vector<long long> ontree;
    for(int i = 1; i < n; i++){
        ontree.push_back((long long)i * (i - 1) / 2 + tree[i]);
        ret.push_back({tree[i], i});
    }
    
    vector<long long> choice = RandomChoice((long long)n * (n - 1) / 2 - (n - 1), m - (n - 1));
    sort(choice.begin(), choice.end());
    
    long long sum = 0;
    int now = 0, at_ontree = 0;
    for(auto i: choice){
        while(at_ontree < n - 1 && ontree[at_ontree] <= i + at_ontree){
            at_ontree++;
        }
        long long x = i + at_ontree;
        while(x - sum >= now){
            sum += now;
            now++;
        }
        int from = int(x - sum), to = now;
        ret.push_back({from, to});
    }
    return ret;
}
