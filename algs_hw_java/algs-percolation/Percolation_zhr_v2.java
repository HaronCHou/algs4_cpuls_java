// import edu.princeton.cs.algs4.QuickUnionUF;
// import QuickUnionUF; // 同一个目录下就不需要package
import edu.princeton.cs.algs4.StdOut;
public class Percolation_zhr_v2 implements Percolation {
    // private QuickUnionUF puf; // cost too much find() calls, 200x more than union(), need to optimize
    private WeightedQuickUnionUF puf;
    private boolean[] stat;
    private int n;

    public Percolation_zhr_v2(int N) {
        StdOut.println(this.getClass());
        n = N;
        // puf = new QuickUnionUF(N * N);
        puf = new WeightedQuickUnionUF(N * N + 2); // +2 for virtual top and bottom
        stat = new boolean[N * N + 2];
        stat[N * N] = true;     // virtual top open
        stat[N * N + 1] = true; // virtual bottom open
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

        if(i == 1){
            puf.union(p, n*n); // connect to virtual top
        }
        if(i == n){
            puf.union(p, n*n+1); // connect to virtual bottom
        }
    }

    public boolean isOpen(int i, int j) {
        int p = xy2index(i, j);
        return stat[p];
    }

    public boolean isFull(int i, int j) {
        int p = xy2index(i,j);
        boolean isconnected = puf.connected(n*n, p);
        return stat[p] && isconnected;
    }

    public boolean percolates() {
        // Check percolation
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (puf.connected(xy2index(1, i), xy2index(n, j))) {
        //             return true;
        //         }
        //     }
        // }
        if (puf.connected(n * n, n * n + 1)) {
            return true;
        }
        return false;
    }
}

