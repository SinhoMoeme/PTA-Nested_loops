# PTA - Nested loops
## PTA - 循环嵌套
_Author 林方圆_<br>
_Organization 广东东软学院_

**计算s=1+（1+2）+（1+2+3）+……+（1+2+……+n）。**
## 输入格式:
输入在一行中给出n的值。

## 输出格式:
在输出行显示计算出的结果。

## 输入样例:
在这里给出一组输入。例如：
```
20
```

## 输出样例：
在这里给出相应的输出。例如：
```
sum=1540
```
---
_By SinhoMoeme_

_題解作者 史行·某萌_

## Summary | 題目大意
There is a sequence which the value of each item is adding from 1 to current number of items.<br>
The length of the sequence is $n$ . Output the sum of the whole sequence.

有一個序列，其每個項目的值是從 1 加到當前項目的數量。<br> 
序列的長度是 $n$。輸出整個序列的總和。

## Brute Force Algorithm | 暴力演算法
``` C++
#include<stdio.h>
int n,s=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j) s+=j;
    }
    printf("sum=%d",s);
    return 0;
}
```

## AC Code | AC程式碼
``` C++
#include<stdio.h>
int n,now=0,s=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        now+=i;
        s+=now;
    }
    printf("sum=%d",s);
    return 0;
}
```
## Explain | 題目講解
First let me explain the BF solution. Input $n$ and initize $s$ to 0 . Then there is a nested loops. The outer `for` enumerate $i$ (means current number of items) from $1$ to $n$. 
The inner `for` enumerate $j$ (means the number which needs to be added) from $1$ to $i$. Each inner `for` will add $s$ by $j$. This operate will properly calculate every item in the 
sequence while adding them all to $s$. So this is a correct BF solution to solve this quesion.

首先我來解釋這個暴力解法。輸入 $n$ 並將 $s$ 初始化為 $0$ 。然後有一個巢狀迴圈。外部 `for` 迴圈從 $1$ 到 $n$ 列舉 $i$（當前的項目數量）。
內部 `for` 迴圈會從 $1$ 到 $i$ 列舉 $j$（當前加數），每次外部 `for` 迴圈會將 $s$ 增加 $j$。這個操作會正確地計算序列中的每一個項目，同時將它們全部加到 $s$ 上。因此，這是本題的一個正確暴力解法。
``` C++
for(int i=1;i<=n;++i){
    for(int j=1;j<=i;++j) s+=j;
}
```
**$s$ won't be assigned to $0$ because it's only assigned to $0$ when initizing. So $s$ will continue to increase until the value is the correct answer.**

**$s$ 不會被指派為 $0$，因為它只有在初始化時才會被指派為 $0$ 。所以 $s$ 會持續增加，直到它的值為正確的答案。**

We can optimize this code since for each item, if it have a predecessor, the value of it equals the value of its predecessor plus $i$. So calculate every value of items from scratch a waste. 
Just save the former value and add it by $i$ will save a lot of time.

我們可以優化這段程式碼，因為對於每個項目，如果它有前任者，它的值等於前任者的值加上 $i$ 。所以從頭計算每個項目的值是一種浪費。只需保存先前的值，每次加 $i$ ，便能節省很多時間。
