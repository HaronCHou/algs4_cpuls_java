
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class WeightedQuickUnionUF {
private:
    vector<int> id;
    vector<int> size;
    int count;

public:
    WeightedQuickUnionUF(int N) {
        count = N;
        id.resize(N);
        size.resize(N, 1); // initialize size array with 1
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
        // Union by size: make smaller tree point to larger one
        if (size[pRoot] < size[qRoot]) {
            id[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        } else {
            id[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        }
        count--;
    }
};
#if 0
int main() {
    int N;
    cin >> N;
    WeightedQuickUnionUF uf(N);

    // 记录开始时间
    auto start = chrono::high_resolution_clock::now();

    while (cin) {
        int p, q;
        if (!(cin >> p >> q)) break;

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
#endif