> - 使用C++复现algs4的java代码和作业；深入理解算法；尝试自己手写代码；同步理解优化点和改进点；

---

# 目录：

- [1.5 union_find](1.5_union_find.md) ：QuickFindUF.cpp, QuickUionUF.cpp, WeightedQuickUnionUF.cpp, WeightedQuickUionPCUF.cpp 四种并查集算法

  - application：二值图标记：CCL 联通域标记；（待补充代码和应用） 参考：YCCLLAB这个库
  - homework: [percolation](hw1_percolation.md)

    > Tips: vscode的代码自动补全功能很好。copolit 想办法多用；
    >
  - 《算法4》课后习题：https://github.com/liangxin1988/Algorithms-4th-Anwser

    - https://github.com/13247574565/Algorithms?tab=readme-ov-file
    - https://blog.csdn.net/u013541140/article/details/53222770
    - https://github.com/aistrate/AlgorithmsSedgewick
- [1.4_analysis_of_algorithms.md](1.4_analysis_of_algorithms.md) 算法分析
- [stacks_and_queues.md](stacks_and_queues.md) 栈和队列

---

# 其他内容

### 一、java环境配置

- 以前的笔记：[普林斯顿算法课 java环境配置](https://blog.csdn.net/haronchou/article/details/78753222) ，以及一些作业参考

1. https://lift.cs.princeton.edu/java/linux/ 官方出了Intellji 2025.2的安装教程

   1. https://youtrack.jetbrains.com/articles/IDEA-A-2100662485/IntelliJ-IDEA-2025.2-252.23892.409-build-Release-Notes 参考发行日志
      ` Plugin 'LIFT-TigerFile' (edu.princeton.cs.lift.tigerfile, version=1.4.0) requires IDE build 232.* or older, but the current build is IC-252.23892.409`

      - LIFT插件，需要IDE build 232.* ，就是IntelliJ 2023.2版本
      - 'Plugin DevKit' (DevKit, version=252.25557.23) requires IDE build 252.25557 又要2025.2版本
   2. 计划先回退232,看是否能出现：LIFT->Recompile, LIFT->Run----cannot
   3. please read https://lift.cs.princeton.edu/java/linux/  for details in faqs

   ```
   2025-09-13 22:30:48,036 [    234]   WARN - #c.i.i.p.PluginManager - Problems found loading plugins:
     Plugin 'Plugin DevKit' (DevKit, version=252.25557.23) requires IDE build 252.25557 or newer, but the current build is IC-252.23892.409
     Plugin 'LIFT-TigerFile' (edu.princeton.cs.lift.tigerfile, version=1.4.0) requires IDE build 232.* or older, but the current build is IC-252.23892.409
   2025-09-13 22:30:48,682 [    880]   WARN - #c.i.i.s.p.i.BundledSharedIndexProvider - Bundled shared index is not found at: /home/dl/zhr/software_package/ideaIC-2025.2/idea-IC-252.23892.409/jdk-shared-indexes
   JCEF_V(30:49:122): Found cef_server binary '/home/dl/zhr/software_package/ideaIC-2025.2/idea-IC-252.23892.409/jbr/lib/cef_server' via System.getProperty('java.home')=/home/dl/zhr/software_package/ideaIC-2025.2/idea-IC-252.23892.409/jbr
   JCEF_V(30:49:122): Java is started via native launcher. Found cef_server path /home/dl/zhr/software_package/ideaIC-2025.2/idea-IC-252.23892.409/jbr/lib/cef_server (via system propety)
   2025-09-13 22:30:50,223 [   2421]   WARN - #c.i.s.c.i.StationSocketConnectionLoop - Discovery connection failed with NoSuchFileException (/run/user/1000/jb.station.sock)
   2025-09-13 22:30:51,178 [   3376]   WARN - #c.i.s.c.i.StationSocketConnectionLoop - RecentProjects connection failed with NoSuchFileException (/run/user/1000/jb.station.sock)

   ```

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

## FAQS

##### 1. github如何push代码？总是鉴权失败？——禁止密码授权；改为ssh-key

```bash
# github已经禁止密码方式访问；替换方式为：ssh-keys形式
进入项目目录，检查当前远程地址：

git remote -v
如果是 HTTPS 地址，替换为 SSH 地址：

git remote set-url origin git@github.com:USERNAME/REPO_NAME.git
若未添加远程地址，可直接添加：

git remote add origin git@github.com:USERNAME/REPO_NAME.git
4. 测试 SSH 连接

运行以下命令验证 SSH 配置是否成功：

ssh -T git@github.com
成功时会显示类似信息：

Hi USERNAME! You've successfully authenticated, but GitHub does not provide shell access
5. 推送代码到远程仓库

初始化或确认本地仓库后推送代码：

git init
git add
git commit -m "Initial commit"
git push -u origin main

```
