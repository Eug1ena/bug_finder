## 概要
競技プログラミングでコードをバグらせたときにバグを見つけるツールです。<br>
バグのあるコード、バグのないコードとテストケース生成コードから反例を探します。<br>
(C++のコードのみ対応)
## 使い方
1. このツール全体をcloneしてください。<br>
`$ git clone https://github.com/Eug1ena/bug_finder`
2. bug_code.cppにバグのあるコードを、<br>
correct_code.cppにバグの無いコードを、<br>
testcase_maker.cppにテストケース生成コードを入れてください。
3. checker.pyを実行して下さい。この時に引数が要りますが、この説明は後述します。<br>
`$ python3 checker.py 引数`
4. 実行すると、反例があれば1つ出力され、無ければ正常に終了した旨が伝えられます。<br>
(ただし、3つのC++のコードのいずれかにコンパイルエラーや実行時エラーがある場合はそれが表示されます。)

### C++のコードの書き方
* bug_code.cpp : 標準入力にテストケースを受け、標準出力にその解答を出力するコードを書いてください。
* correct_code.cpp : 標準入力にテストケースを受け、標準出力にその解答を出力するコードを書いてください。
* testcase_maker.cpp : 標準出力にテストケース1個分を出力するコードを書いてください。入力は特に無いので、乱数を使って各テストケースで値をばらつかせるのが良いでしょう。

### checker.pyの呼び出し方
checker.pyの呼び出しには引数が必要です。<br>
`$ python3 checker.py 引数`<br>
この引数は、試すテストケースの個数を表します。必要に応じて100や1000など適当に選びましょう。<br>
例 : `$ python3 checker.py 1000`<br>

### 反例の書式
#### 反例があった場合
```
[9th testcase]
testcase:
5 5

wrong:
10

correct:
over
```
テストケース番号(1-indexed)、テストケースの内容、バグコードの出力、バグの無いコードの出力が表示されます。
#### 反例が無かった場合
```
No bug is found.
```
とだけ表示されます。
