# Library

断りがない限り、以下の値は全て0-indexedです。

## choose

```
T rnd::choose(T n)
```

[0, n) の範囲から整数をランダムに 1 個選びます。

```
T rnd::choose(T l, T r)
```

[l, r] の範囲から整数をランダムに 1 個選びます。

## array

```
vector<T> rnd::array(T n, int k)
```

[0, n) の範囲から相異なる整数をランダムに k 個選びます。

計算量: O(k)

## tree

```
vector<pair<int, int>> rnd::tree(int n)
```

n 頂点の木をランダムに構築します。

計算量: O(n)

## graph

```
vector<pair<int, int>> rnd::graph(int n, int m)
```

n 頂点 m 辺の連結とは限らない単純無向グラフをグラフをランダムに構築します。

計算量: O(m)

## connected_graph

```
vector<pair<int, int>> rnd::connected_graph(int n, int m)
```

n 頂点 m 辺の連結な単純無向グラフをランダムに構築します。

計算量: O(m)