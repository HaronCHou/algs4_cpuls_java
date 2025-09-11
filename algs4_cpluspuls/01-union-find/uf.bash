#!/bin/bash

# 可执行文件名
CLASS_NAME=$1

# 输出文件名
OUTPUT_FILE="output/$(echo $CLASS_NAME | sed 's/^build\///')_res.txt"

# 输出文件名
echo "Output will be written to: $OUTPUT_FILE"

# 运行不同的输入文件并将输出合并到同一个结果文件
$CLASS_NAME < input/tiny.txt > $OUTPUT_FILE &&
$CLASS_NAME < input/mediumUF.txt >> $OUTPUT_FILE &&
$CLASS_NAME < input/largeUF.txt >> $OUTPUT_FILE

# usage: 
# bash uf.bash build/QuickFindUF
# bash uf.bash build/QuickUionUF
# bash uf.bash build/WeightedQuickUnionUF
# bash uf.bash build/WeightedQuickUnionPCUF