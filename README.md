# bug_finder

bug_finderはテストケースをランダム生成してバグを見つける、競プロ用のデバッグツールです。<br>

現状はC++17にのみ対応しています。今後増やすかもしれません。<br>
また、このツールを使う際には自己責任でお願いします。

## 導入方法

このリポジトリをcloneします。

```
$ git clone https://github.com/Eug1ena/bug_finder
```

## 使用方法

bug_finder/code/testcase.cpp, wrong.cpp, correct.cpp に該当のコードをそれぞれ置きます。

checker.pyを実行します。

```
$ python3 bug_finder/checker.py [テストケース数]
```

詳細な使い方は [How to use](How to use.md) を参照してください。

## ライブラリ

library.hppをインクルードすることで、ランダム関係のいくつかのライブラリが利用できます。

ライブラリの一覧は [Library](Library.md) を参照してください。