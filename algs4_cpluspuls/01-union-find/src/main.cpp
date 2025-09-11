#include <iostream>
#include "uf.h"
#include "findDuplicates.h"

#include "quick_uion.h"
#include "quick_union_v2.h"
#include "quick_union_v3.h"


int main(int args, char* argv[])
{
    // get_result();
    // quick_find_test();   // 树是扁平的，查找快，union操作复杂度高O(M*N)
    // quick_union_test_v1();  // v1 == v2 
    // quick_union_test_v2();  // 不用遍历所有的数组，就能实现根和根的合并，但还是无法处理大型问题
    // quick_union_test_v3();
    // 主要是对N的数组进行M次union时，如何降低时间开销
    // 1. 降低树的查找高度-->depth(tree) < log2(N)



    // 批量进行：https://algs4.cs.princeton.edu/15uf/
    quick_find_txt("/home/dl/zhr/code/algs4/01-union-find/input/tiny.txt");
    quick_find_txt("/home/dl/zhr/code/algs4/01-union-find/input/mediumUF.txt");
    // quick_find_txt("/home/dl/zhr/code/algs4/01-union-find/input/largeUF.txt");

// v1有bug
    // quick_union_v1_txt("/home/dl/zhr/code/algs4/01-union-find/input/tiny.txt");
    // quick_union_v1_txt("/home/dl/zhr/code/algs4/01-union-find/input/mediumUF.txt");
    // quick_union_v1_txt("/home/dl/zhr/code/algs4/01-union-find/input/largeUF.txt");
// quick-find 规模=10 unions次数=9     共有连通分量=3 components!     cost=4ms
// quick-find 规模=625        unions次数=844   共有连通分量=-218 components!  cost=709ms

// quick-uion 规模=10 unions次数=8     共有连通分量=2 components!     cost=3ms
// quick-uion 规模=625        unions次数=594   共有连通分量=31 components!    cost=217ms

    quick_union_v2_txt("/home/dl/zhr/code/algs4/01-union-find/input/tiny.txt");
    quick_union_v2_txt("/home/dl/zhr/code/algs4/01-union-find/input/mediumUF.txt");
    quick_union_v2_txt("/home/dl/zhr/code/algs4/01-union-find/input/largeUF.txt");

    // quick_union_weighted
    quick_union_v3_txt("/home/dl/zhr/code/algs4/01-union-find/input/tiny.txt");
    quick_union_v3_txt("/home/dl/zhr/code/algs4/01-union-find/input/mediumUF.txt");
    quick_union_v3_txt("/home/dl/zhr/code/algs4/01-union-find/input/largeUF.txt");



    return 0;
}





