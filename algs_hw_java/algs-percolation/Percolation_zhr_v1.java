// import edu.princeton.cs.algs4.QuickUnionUF;
// import QuickUnionUF; // 同一个目录下就不需要package
import edu.princeton.cs.algs4.StdOut;
public class Percolation_zhr_v1 implements Percolation {
    // private QuickUnionUF puf; // cost too much find() calls, 200x more than union(), need to optimize
    private WeightedQuickUnionUF puf;
    private boolean[] stat;
    private int n;

    public Percolation_zhr_v1(int N) {
        StdOut.println(this.getClass());
        n = N;
        // puf = new QuickUnionUF(N * N);
        puf = new WeightedQuickUnionUF(N * N);
        stat = new boolean[N * N];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                stat[xy2index(i, j)] = false; // closed
            }
        }
    }

    public int getfindCount() {
        return puf.getfindCount();
    }
    public int getUnionCount() {
        return puf.getUnionCount();
    }

    public int xy2index(int i, int j) {
        return (i-1) * n + j  - 1;
    }

    public void open(int i, int j) {
        int p = xy2index(i, j);
        stat[p] = true; // open
        // union with its open neighbors
        if (i - 1 >= 1 && isOpen(i - 1, j)) { // up
            puf.union(p, xy2index(i - 1, j));
        }
        if (i + 1 <= n && isOpen(i + 1, j)) { // down
            puf.union(p, xy2index(i + 1, j));
        }
        if (j - 1 >= 1 && isOpen(i, j - 1)) { // left
            puf.union(p, xy2index(i, j - 1));
        }
        if (j + 1 <= n && isOpen(i, j + 1)) { // right
            puf.union(p, xy2index(i, j + 1));
        }
    }

    public boolean isOpen(int i, int j) {
        int p = xy2index(i, j);
        return stat[p];
    }

    public boolean isFull(int i, int j) {
        int p = xy2index(i, j);
        if (!stat[p]) return false;
        for (int col = 1; col <= n; col++) {
            boolean isconnected = puf.connected(xy2index(1, col), xy2index(i, j));
            if (isconnected) return true;
        }
        return false;
    }

    public boolean percolates() {
        // Check percolation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (puf.connected(xy2index(1, i), xy2index(n, j))) {
                    return true;
                }
            }
        }
        return false;
    }
}

