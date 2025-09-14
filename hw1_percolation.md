1. C++里面记录每个site的状态，open/close是用二维数组，还是用 `vector<vector<int>>`呢？ 二维vector是如何存储的？如何使用的？底层是怎么的？

```bash
1. (i,j)为[0，N-1]，N*N；暂时不做虚拟节点；判断是否percolates时先做循环；先做基础工作，正确性，再考虑优化；
2. stat数组的表示形式？bool数组？还是vector形式？
3. open、close的状态要如何利用起来？
```

- C++版本/percolates_2层for循环遍历 `./Percolation < ../input/10_1.txt` C++可执行文件；

```c++
// PercolationStats.cpp
int main(int argc, char* argv[]){
  // 
  int N, T;
  while(std::cin >> N >> T)
  {
      PercolationStats pls(N, T);
  }

  return 0;
}
```

```bash
(base) dl@dl:~/zhr/code/algs4/algs_hw_cplusplus/percolation/build$ ./Percolation < ../input/10_1.txt 
grid:10,20次    cost=0.1078ms           mean = 0.515     stddev = 0.120208       95% confidence interval = [0.3484, 0.6816]
grid:20,20次    cost=1.50575ms          mean = 0.615     stddev = 0.0106066      95% confidence interval = [0.6003, 0.6297]
grid:30,20次    cost=7.8093ms           mean = 0.588333  stddev = 0.101352       95% confidence interval = [0.447867, 0.7288]
grid:40,20次    cost=24.8084ms          mean = 0.603125  stddev = 0.0521491      95% confidence interval = [0.53085, 0.6754]
grid:50,20次    cost=54.6999ms          mean = 0.5942    stddev = 0.0115965      95% confidence interval = [0.578128, 0.610272]
grid:60,20次    cost=119.849ms          mean = 0.577083  stddev = 0.00923168     95% confidence interval = [0.564289, 0.589878]
grid:70,20次    cost=215.894ms          mean = 0.59949   stddev = 0.0197701      95% confidence interval = [0.57209, 0.62689]
grid:80,20次    cost=375.698ms          mean = 0.591484  stddev = 0.00806543     95% confidence interval = [0.580306, 0.602663]
```

把时间开销在python中绘制为图，脚本为：[algs_hw_cplusplus/percolation/result.ipynb](algs_hw_cplusplus/percolation/result.ipynb) 

- 时间复杂度拟合如下所示：由于grid-size实际为$N^2$，所以时间开销更接近于$O(N^3)$

![img](images/percolatetime.png)

)![img](images/percolation时间复杂度.png "时间复杂度拟合")
