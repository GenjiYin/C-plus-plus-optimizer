# C++优化算法
## 二次函数逼近求解(一维情况)
步骤1: 手动确定分割点, 如要求[0, 1]区间内最小值, 可选择分割点0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 如此便将区间分割成十份.

步骤2：搜索边界点和分割点的最小值对应的坐标点
$x_i$
, 并获取前一个点
$x_{i-1}$
以及后一个点
$x_{i+1}$
, 并获取他们的函数值.

步骤3：三点确定一条二次函数曲线, 可分为四种情况讨论:
