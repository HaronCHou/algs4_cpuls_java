javac-algs4 *.java # 多个文件一起命令行编译

java-algs4 PercolationVisualizer  input/input6.txt 0 
java-algs4 PercolationVisualizer  input/input8.txt 0
java-algs4 PercolationVisualizer  input/input8-no.txt 0
java-algs4 PercolationVisualizer  input/input10-no.txt 0
java-algs4 PercolationVisualizer  input/greeting57.txt 0
java-algs4 PercolationVisualizer  input/heart25.txt 0


java-algs4 PercolationStats 8 1 > output/zhr_v1_out.txt
java-algs4 PercolationStats 32 1 >> output/zhr_v1_out.txt
java-algs4 PercolationStats 128 1 >> output/zhr_v1_out.txt
java-algs4 PercolationStats 512 1 >> output/zhr_v1_out.txt
java-algs4 PercolationStats 1024 1 >> output/zhr_v1_out.txt

java-algs4 PercolationStats 8 1 > output/zhr_v2_out_WeightedQuickUnionUF.txt
java-algs4 PercolationStats 32 1 >> output/zhr_v2_out_WeightedQuickUnionUF.txt
java-algs4 PercolationStats 128 1 >> output/zhr_v2_out_WeightedQuickUnionUF.txt
java-algs4 PercolationStats 512 1 >> output/zhr_v2_out_WeightedQuickUnionUF.txt
java-algs4 PercolationStats 1024 1 >> output/zhr_v2_out_WeightedQuickUnionUF.txt