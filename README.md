# 3.HighPrecOperation

简单的高精度运算，包括加法、减法、乘法、阶乘。

## 加法

加法的原理很简单

```cpp
for (int i = 0; i < len; i++) {

	ans[i] += x[i] + y[i];

	if (ans[i] >= 10) {
		ans[i + 1]++;
		ans[i] %= 10;
	}
}
```

就是将每一位相加，如果结果大于 10 就进位。

## 减法

减法的原理与加法大同小异

```cpp
for (int i = 0; i < len; i++) {

	x[i] = x[i] - y[i];

	if (x[i] < 0) {
		x[i + 1]--;
		x[i] += 10;
	}
}
```

将每一位相减，如果结果为负数就从前一位借 1。

但减法有可能有负数的情况，于是加入了负数判断

```cpp
if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
	swap(x, y);
	isNegative = true;
}
```

1. 如果被减数的位数小于减数的位数，那么被减数小于减数，结果为负数
2. 如果被减数的位数等于减数的位数，但 `string::operator<(a, b)` 的结果为 `true` 则被减数小于减数，结果为负数

## 乘法

核心代码为

```cpp
for (int i = 0, carry = 0; i < x.size(); i++) {
	carry = 0;
	for (int j = 0; j < y.size(); j++) {
		ans[i + j] += x[i] * y[j] + carry;
		carry = ans[i + j] / 10;
		ans[i + j] %= 10;
	}
	ans[y.size() + i] += carry;
}
```

用 x 的每一位与 y 的所有位相乘，结果叠加到 ans 中。

## 阶乘

其实就是乘法的的叠加，没有技术含量。