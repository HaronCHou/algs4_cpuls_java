#include "visTree.h"

class QuickUion{
public:
    QuickUion(int n)
    {
        cnt = n;
        components_counts = n;
        id = new int[n];
        // Initialization 初始化均为互不相连
        for(int i=0; i<n; i++){
            id[i] = i;
            sz[i] = 1;
        }
    }

    ~QuickUion()
    {
        delete[] id;
    }

    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }
    int* root(int p)
    {
        size_t array_visit_cnts = 0;
        // 递归
        while(p != id[p]){
            p = id[p];
            array_visit_cnts++;
        }
        //  std::cout << "find array_visit_cnts=" << array_visit_cnts << std::endl;
        return &id[p];
    }

    void union_v1(int p, int q)
    {
        int* root_p = root(p);
        int* root_q = root(q);
        if(root_p == root_q) return;
        *root_q = *root_p;
        components_counts--;
    }
    int count()
    {
        return components_counts;
    }
    // 打印当前状态
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
private:
    int* id;    
    int cnt;
    int* sz;
    int components_counts;
};

void quick_union_test_v1(const std::string str)
{
    QuickUion uf(10);
    // uf.printf_id();

    uf.union_v1(4,1);
    uf.union_v1(2,3);
    uf.union_v1(4,5);
    uf.union_v1(3,6);

    uf.union_v1(1,6);

    uf.printf_id();

    // 有几组？每一组有哪些元素？连通路径是啥？
    // std::cout << uf.connected(1,5) << std::endl;
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

void quick_union_v1_txt(const std::string str)
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

    QuickUion uf(N);

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
            uf.union_v1(a,b);
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