#pragma once
#include "QuickUionUF.h"


class Percolation{
public:
    Percolation(int N){
        n = N;
        puf = new QuickUnionUF(N*N);
        // stat.resize(N, vector<bool>(N, false)); // N*N grid, all close
        stat = new bool[N*N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                stat[xy2index(i, j)] = false; // close
    }
    ~Percolation(){
        delete puf;
        delete[] stat;
    }
    int xy2index(int i, int j) // i行j列, i\in[0,n-1], j\in[0,n-1]
    {
        return i*n + j;
    }
    void open(int i, int j){
        int p = xy2index(i, j);
        stat[p] = true; // open
        // union with its open neighbors
        if(i-1 >= 0 && isOpen(i-1, j)) // 上
            puf->unionOp(p, xy2index(i-1, j));
        if(i+1 < n && isOpen(i+1, j)) // 下
            puf->unionOp(p, xy2index(i+1, j));
        if(j-1 >= 0 && isOpen(i, j-1)) // 左
            puf->unionOp(p, xy2index(i, j-1));  
        if(j+1 < n && isOpen(i, j+1)) // 右
            puf->unionOp(p, xy2index(i, j+1));
    }
    bool isOpen(int i, int j){
        int p = xy2index(i, j);
        return stat[p];
    }

    bool isFull(int i, int j){
        for(int i = 0; i < n; i++)
        {
            for(int j=0; j < n; j++)
            {
                if(puf->connected(xy2index(0, i), xy2index(n-1, j))) // 第0行和最后一行逐个对比
                        return true;
            }
        } 
    }
    bool percolates(){
        // 先不使用虚拟节点
        // 逐个遍历第0行和最后一行是否相连
        clock_t start, end;
        start = clock();
        // std::cout << "check percolates..." << std::endl;
        for(int i = 0; i < n; i++)
        {
            for(int j=0; j < n; j++)
            {
                if(puf->connected(xy2index(0, i), xy2index(n-1, j))) // 第0行和最后一行逐个对比
                        return true;
            }
        }
        end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        // std::cout << "check percolates time: " << duration * 1000 << " ms."<< std::endl;
        // std::cout << "not percolates." << std::endl;
        return false;
    }

private:
    QuickUnionUF* puf;
    // int virtual_head; // rand~[1,N]
    // int vitural_end;
    int n;
    // vector<vector<bool>> stat; // 记录每个site的状态，open/close
    bool* stat; // 记录每个site的状态，open/close
};