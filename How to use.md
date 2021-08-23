# How To Use

## コード

デバッグに使用するコードは以下の要請を満たすように書いてください。

* testcase.cpp : 標準出力にテストケース1個分を出力します。
* wrong.cpp : 標準入力にテストケースを受けて、標準出力にその解答を出力します。
* correct.cpp : 標準入力にテストケースを受けて、標準出力にその解答を出力します。

## 出力

wrong.cpp と correct.cpp が異なる出力をするようなテストケースが見つかった場合、それが出力されます。

```
[9th testcase]
testcase:
5 5

wrong:
10

correct:
over
```
wrong.cpp と correct.cpp の出力が全てのケースで同じだった場合、その旨が出力されます。

```
MESSAGE: No Bug Found
```