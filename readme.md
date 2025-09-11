### 一、java环境配置
1. Linux IDEA 安装及环境配置：https://blog.csdn.net/haronchou/article/details/135597443
2. 普林斯顿算法课 Java环境配置 https://blog.csdn.net/haronchou/article/details/78753222

> - C++是自己实现；java是同步验证；java课程本身是有源码参考的。
> - C++自己实现更印象深刻。
> - coding

#### 1.1 linux java 编程环境设置
1. algs4官方教程地址：https://lift.cs.princeton.edu/java/linux/
```bash 
sudo apt-get install openjdk-11-jdk
javac -version # javac 11.0.27
java -version # 执行
# javac编译 
javac Helloword.java # 源码
java Helloword # 可执行文件

# step2:安装教科书库和其他一来
sudo apt-get install curl 
sudo curl -O "https://lift.cs.princeton.edu/java/linux/lift-cli.zip" # 可以浏览器下载再复制过去，速度快

java-introcs StdAudio # 测试是否安装成功

```
2. algs4的官方hello demo要打开到子工程去编译才行；
	终端下javac 编译和java实现，都是可以，可以利用到 教材库 algs4的绘制库。

#### 1.2 java代码测试
1. 官方代码：https://github.com/RQTN/algs4

- [kevin-wayne/algs4](https://github.com/kevin-wayne/algs4)：官方维护的 Github 仓库

- [jimmysuncpt/Algorithms - Github](https://github.com/jimmysuncpt/Algorithms)：国内某同学答案（较完整）

- [aistrate/AlgorithmsSedgewick - Github](https://github.com/aistrate/AlgorithmsSedgewick)：国外某同学答案

- python版本的复现algs4

  - [Python](https://github.com/itu-algorithms/itu.algs4) by ITU Copenhagen

  - [Python](https://github.com/shellfly/algs4-py) by Li Hao

# 算法4

## 1.5 union-find

- 代码：`/home/dl/zhr/code/algs4/algs4_java/algs4-master-RQTN/algs4-master/src/union_find`

  - terminal: `javac-algs4 xxx.java`, `java-algs4 xxx` 这样才能找到algs4库的依赖；然后执行；

  ```bash
  ~/zhr/code/algs4/algs4_java/algs4-master-RQTN/algs4-master/src$ java-algs4 union_find.QuickFindUF < union_find/input/tiny.txt 
  # 这样才运行成功，也是不理解；
  包名：union_find
  路径：得在union_find上层文件夹
  输入：< 
  输出：>
  ```

|                        | tiny  | medium | large     |
| ---------------------- | ----- | ------ | --------- |
| QuickFindUF            | 1ms   | 8ms    | 36674.0ms |
| QuickUnionUF           | 1ms   | 9ms    | 242.0ms   |
| WeightedQuickUnionUF   | 0.0ms | 7.0ms  | 253ms     |
| WeightedQuickUnionPCUF | 0.0ms | 7.0ms  | 264ms     |

- C++版本：
  - 有bug需要优化

```bash
规模=10 unions次数=8     共有连通分量=2 components!     cost=4ms
规模=625        unions次数=622   共有连通分量=3 components!     cost=582ms
规模=10 unions次数=8     共有连通分量=2 components!     cost=3ms
规模=625        unions次数=622   共有连通分量=3 components!     cost=256ms
规模=1000000    unions次数=242461        共有连通分量=757539 components!        cost=69355ms
规模=10 unions次数=8     共有连通分量=2 components!     cost=4ms
规模=625        unions次数=622   共有连通分量=3 components!     cost=258ms
规模=1000000    unions次数=242461        共有连通分量=757539 components!        cost=75841ms
```

