# bug_finder

テストケースをランダム生成してバグを見つける、競プロ用のデバッグツールです。<br>

現状は C++17 にのみ対応しています。言語は今後増やすかもしれません。<br>
このツールを使う際には自己責任でお願いします。

## 導入方法

このリポジトリを clone します。

```
$ git clone https://github.com/Eug1ena/bug_finder
```

## 使用方法

code ディレクトリ下の testcase.cpp, wrong.cpp, correct.cpp に該当のコードをそれぞれ置きます。

checker.py を実行します。

```
$ python3 checker.py [テストケース数]
```

詳細な使い方は [How to use](/HowToUse.md) を参照してください。

## ライブラリ

library.hpp をインクルードすることで、ランダム関係のいくつかのライブラリが利用できます。

ライブラリの一覧は [Library](/Library.md) を参照してください。