#pragma once
#include <vector>
#include "visTree.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <chrono>

/*
    input: [4,1],[2,3],[4,5],[3,6]
    output: 2, (1,4,5) (2,3,6) (0) (7) (8) (9)
*/
class UF{
public:
    UF(int n){
        cnt = n;
        components_counts = n;
        id = new int[n];
        // sz = new int[n];
        // Initialization 初始化均为互不相连
        for(int i=0; i<n; i++){
            id[i] = i;
            // sz[i] = 1;
        }
    }
    ~UF()
    {
        delete[] id;
        // delete[] sz;
    }
    // 这个有问题，要优化
#if 0    
    void union_(int p, int q)
    {
        int& root_p = find(p);
        int& root_q = find(q);
        if(root_p == root_q) return;
        else if(root_p < root_q)
        {
            root_q = root_p;
        }
        else{ 
            root_p = root_q;
        }
    }   
#else
    void union_(int p, int q)
    {
        if(!validate_indx(p)) return;
        if(!validate_indx(q)) return;
        size_t array_visit_cnts = 0;

        int root_p = find(p);
        int root_q = find(q);
        if(root_p == root_q) return;
        for(int i = 0; i < cnt; i++)
        {
            array_visit_cnts++;
            if(id[i] == root_q)
            {
                id[i] = root_p;               
            }
        }
        components_counts--;      

        // std::cout << "array_visit_cnts=" << array_visit_cnts << std::endl;
    }
#endif
    // quick-find方法
    bool connected(int p, int q){
        if(validate_indx(p) && validate_indx(q))
            return find(p) == find(q);
    }
    int find(int p)
    {
        if(validate_indx(p)) return id[p];
    }
    int count()
    {
        return components_counts;
    }
    bool validate_indx(int p)
    {
        return (p >= 0 &&  p < cnt);
    }

    void printf_id()
    {
        std::cout << "idx:";
        for(int i = 0; i < cnt; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "val:";
        for(int i = 0; i < cnt; i++)
        {
            std::cout << id[i] << " ";
        }
        std::cout <<std::endl;
    }
    void print_tree()
    {
        // 构建森林
        vector<int> parent;
        for(int i = 0; i < cnt; i++)
        {
            parent.push_back(id[i]);
        }
        vector<TreeNode*> forest = buildForest(parent);
        
        // 可视化输出
        printForest(forest);
    }
    /*
        https://leetcode.cn/problems/find-all-duplicates-in-an-array/description/
        leetcode类似题目：数组中重复的数据
    */
    void get_groups()
    {
        // 问题：二维vector的空间是怎么排序的？
        // 问题：有没有更简单的方式？
        std::vector<std::vector<int>> groups_id(cnt);
        for(int i = 0; i < cnt; i++)
        {
            groups_id[id[i]].push_back(i);
        }

        for(int i = 0; i < cnt; i++)
        {
            int sz = groups_id[i].size();
            if( sz > 1)
            {
                std::cout << "idx=" << i << "\t";
                for(int j = 0; j < sz; j++)
                {
                    std::cout << groups_id[i][j] << " ";
                }
                std::cout << "\n";
            }
        }
    }

 
private:
    int* id;
    // int* sz;
    int cnt;
    int components_counts;
};


   void quick_find_test()
    {
        UF uf(10);
        // uf.printf_id();

        uf.union_(4,1);
        uf.union_(2,3);
        uf.union_(4,5);
        uf.union_(3,6);

        uf.union_(1,6);

        uf.printf_id();

        // 有几组？每一组有哪些元素？连通路径是啥？
        // std::cout << uf.connected(1,5) << std::endl;
        uf.get_groups();
        uf.print_tree();

        /* 局限性：M次Union，需要访问数组M*N次；O(M*N)，时间复杂度太高了
                原因：没有解决数据存储的结构问题。
                    上述属于quick-find算法，在操作次数不多的时候适合。
                如果union次数太多，需要优化
                    quick-union算法，在多次union时，尽量少的访问数组。
        */
    #if 0 // 输出如下：
        array_visit_cnts=10
        array_visit_cnts=10
        array_visit_cnts=10
        array_visit_cnts=10
        array_visit_cnts=10
        idx:0 1 2 3 4 5 6 7 8 9 
        val:0 1 1 1 1 1 1 7 8 9 
        idx=1   1 2 3 4 5 6 
    #endif

    }

     void quick_find_txt(const std::string str)
     {

        std::ifstream file(str);

        if(!file.is_open())
        {
            std::cerr << "cannot open file \n";
        }

        int N = 0;
        std::string   firstLine;
        if(getline(file, firstLine)){
            std::stringstream ss(firstLine);
            ss >> N;
            // cout << "scale: " << N << endl;
        }

        UF uf(N);

        std::string line;

        size_t count_union_times = 0;
        auto start = std::chrono::high_resolution_clock::now();
        while(getline(file, line))
        {
            if(line.empty()) continue;
            std::stringstream ss(line);
            int a, b;
            if(ss>>a>>b){
                if(uf.connected(a, b)) continue;
                uf.union_(a,b);
                count_union_times++;
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "规模=" << N << "\tunions次数="<<
            count_union_times <<"\t 共有连通分量="<< uf.count() << " components!";
        std::cout << "\tcost=" << duration.count() << "ms\n";
        file.close();
     }
