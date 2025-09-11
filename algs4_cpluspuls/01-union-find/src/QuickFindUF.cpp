#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class QuickFindUF {
private:
    vector<int> id;
    int count;

public:
    QuickFindUF(int N) {
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
        return id[p];
    }

    bool connected(int p, int q) const {
        return find(p) == find(q);
    }

    void unionOp(int p, int q) {
        int pID = find(p);
        int qID = find(q);
        if (pID == qID) {
            return;
        }
        for (int i = 0; i < id.size(); i++) {
            if (id[i] == pID) {
                id[i] = qID;
            }
        }
        count--;
    }
};

int main() {
    int N;
    cin >> N;
    QuickFindUF uf(N);

    // 记录开始时间
    auto start = chrono::high_resolution_clock::now();

    while (!cin.eof()) {
        int p, q;
        if (!(cin >> p >> q)) break;  // 如果输入无效，退出循环

        if (uf.connected(p, q)) {
            continue;
        }
        uf.unionOp(p, q);
    }

    // 记录结束时间
    auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> duration = end - start;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "  >>>  Input file: " << uf.getCount() << " components  cost " 
         << duration.count() << " ms" << endl;

    return 0;
}
