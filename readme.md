- [1.5 union_find](1.5_union_find.md)
  - application
    - 二值图标记：CCL 联通域标记；
  - homework: [percolation](hw1_percolation.md)


### 一、java环境配置

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

