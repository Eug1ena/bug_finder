## 概要
競技プログラミングでコードをバグらせたときにバグを見つけるツールです。<br>
バグのあるコード、バグの無いコードとテストケース生成コードから反例を探します。<br>

現状はC++17のコードにのみ対応しています。今後増やすかもしれません。<br>
また、このツールを使う際には自己責任でお願いします。

## 使い方
1. [Releases](https://github.com/Eug1ena/bug_finder/releases) で最新版の bug_finder.zip をダウンロード、展開します。
2. code/wrong.cppにバグのあるコードを、<br>
code/correct.cppにバグの無いコードを、<br>
code/testcase.cppにテストケース生成コードを書きます。
3. checker.pyを実行します。この時に引数が要りますが、この説明は後述します。<br>
`$ python3 checker.py 引数`
4. 実行すると、反例が1つ出力されるか、反例が無ければ正常に終了した旨が伝えられます。<br>
(ただし、3つのC++のコードのいずれかにコンパイルエラーや実行時エラーがある場合はそれが表示されます。)

### C++のコードの書き方
* wrong.cpp : 標準入力にテストケースを受け、標準出力にその解答を出力するコードを書いてください。
* correct.cpp : 標準入力にテストケースを受け、標準出力にその解答を出力するコードを書いてください。
* testcase.cpp : 標準出力にテストケース1個分を出力するコードを書いてください。入力は特に与えられないので、乱数を使って各テストケースで値をばらつかせるのが良いでしょう。

### checker.pyの呼び出し方
checker.pyの呼び出しには引数が必要です。<br>
`$ python3 checker.py 引数`<br>
この引数は、試すテストケースの個数を表します。必要に応じて100や1000など適当に選びましょう。<br>
例 : `$ python3 checker.py 1000`<br>

### 反例の書式
#### 反例が見つかった場合
```
[9th testcase]
testcase:
5 5

wrong:
10

correct:
over
```
テストケース番号(1-indexed)、テストケースの内容、バグのあるコードの出力、バグの無いコードの出力が表示されます。
#### 反例が見つからなかった場合
```
MESSAGE: No Bug Found
```
とだけ表示されます。
