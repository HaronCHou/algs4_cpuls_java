# 可视化的部分失败了；但是还是可以测试是否渗透: input: xxx.txt outpu: yes/no
# ./build/PercolationStats < ./input/input/input6.txt > ./output/output6.txt


# 这个只是看和官网的逻辑是否一样
./build/PercolationVisualizer < ./input/input/input6.txt > ./output/output6.txt
# build dir:
#  ./PercolationVisualizer < ../input/input/input6.txt > ../output/output6.txt