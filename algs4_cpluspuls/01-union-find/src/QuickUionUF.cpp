#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class QuickUnionUF {
private:
    vector<int> id;
    int count;

public:
    QuickUnionUF(int N) {
        count = N;
        id.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    int getCount() const {
        return count;
    }

    int find(int p) const {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    bool connected(int p, int q) const {
        return find(p) == find(q);
    }

    void unionOp(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) {
            return;
        }
        id[pRoot] = qRoot;
        count--;
    }
};

int main() {
    int N;
    cin >> N;
    QuickUnionUF uf(N);

    // 记录开始时间
    auto start = chrono::high_resolution_clock::now();

    while (cin) {
        int p, q;
        if (!(cin >> p >> q)) break;  // 如果输入无效，退出循环

        if (uf.connected(p, q)) {
            continue;
        }
        uf.unionOp(p, q);
    }

    // 记录结束时间
    auto end = chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "  >>>  Input file: " << uf.getCount() << " components  cost " 
         << duration.count() << " ms" << endl;

    return 0;
}
