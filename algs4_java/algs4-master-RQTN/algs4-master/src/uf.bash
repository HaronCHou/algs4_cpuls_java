# java-algs4 union_find.QuickFindUF < union_find/input/tiny.txt > union_find/output/QuickFindUF_tiny_res.txt &&
# java-algs4 union_find.QuickFindUF < union_find/input/mediumUF.txt > union_find/output/QuickFindUF_medium_res.txt &&
# java-algs4 union_find.QuickFindUF < union_find/input/largeUF.txt > union_find/output/QuickFindUF_large_res.txt

# java-algs4 union_find.QuickFindUF < union_find/input/tiny.txt > union_find/output/QuickFindUF_res.txt &&
# java-algs4 union_find.QuickFindUF < union_find/input/mediumUF.txt >> union_find/output/QuickFindUF_res.txt &&
# java-algs4 union_find.QuickFindUF < union_find/input/largeUF.txt >> union_find/output/QuickFindUF_res.txt

# 追加方式输出到一个文件中

#!/bin/bash

# 获取传入的类名参数
CLASS_NAME=$1

# 生成输出文件名（以类名为基础）
OUTPUT_FILE="union_find/output/$(echo $CLASS_NAME | sed 's/\./_/g')_res.txt"

# 输出文件名
echo "Output will be written to: $OUTPUT_FILE"

# 运行不同的输入文件并将输出合并到同一个结果文件
java-algs4 $CLASS_NAME < union_find/input/tiny.txt > $OUTPUT_FILE &&
java-algs4 $CLASS_NAME < union_find/input/mediumUF.txt >> $OUTPUT_FILE &&
java-algs4 $CLASS_NAME < union_find/input/largeUF.txt >> $OUTPUT_FILE


# bash uf.bash union_find.QuickFindUF
# bash uf.bash union_find.QuickUnionUF
# bash uf.bash union_find.WeightedQuickUnionUF
# bash uf.bash union_find.WeightedQuickUnionPCUF
