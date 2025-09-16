import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stopwatch;
// import Percolation_zhr_v1;
// import PercolationAnswer;


public class PercolationStats {
    
    private double[]    threshold;

    // perform T independent computational experiments on an N-by-N grid
    public PercolationStats(int N, int T) {

        int openCount, row, column;

        if (N <= 0 || T <= 0)
            throw new IllegalArgumentException("Arguments out of bound");

        threshold = new double[T];
        
        openCount = 0;
        for (int i = 0; i < T; i++) {        
            /* 重载多个类，切换着用
                0-PercolationAnswer 标准答案里的
                1-Percolation_zhr_v1 自己写的
            */
        //    Percolation pl = new PercolationAnswer(N);
            // Percolation    pl = new Percolation_zhr_v1(N);
            Percolation    pl = new Percolation_zhr_v2(N);
            // Percolation    pl = new Percolation_zhr_v3(N);
            // StdOut.println(pl.getClass());
            do {
                row     = StdRandom.uniform(1, N+1);
                column  = StdRandom.uniform(1, N+1);
                if (pl.isOpen(row, column))
                    continue;
                pl.open(row, column);
                openCount++;
            } while (!pl.percolates());

            threshold[i] = (double) openCount / (N * N);
            StdOut.println("open() = " + openCount + " site()/percolates() " + "union() = " +pl.getUnionCount() + "\t find() = " 
            + pl.getfindCount() + "\t" + "raio=" + (double)pl.getfindCount() / (double)pl.getUnionCount() );

            openCount = 0;
        }
    }

    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(threshold);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        return StdStats.stddev(threshold);
    }

    private double halfInterval() {
        return 1.96 * stddev() / Math.sqrt(threshold.length);
    }
    
    // returns lower bound of the 95% confidence interval
    public double confidenceLo() {
        return mean() - halfInterval();
    }
    
    // returns upper bound of the 95% confidence interval
    public double confidenceHi() {
        return mean() + halfInterval();
    }
    
    // test client, described below
    public static void main(String[] args) {
        Stopwatch timer = new Stopwatch();
        PercolationStats pls = new PercolationStats(Integer.parseInt(args[0]),
                    Integer.parseInt(args[1])); // N,T
        double time = timer.elapsedTime();
        StdOut.println("N="+args[0]+" T="+args[1]+ "\t time = " + time + " seconds\t" +
            "mean = "+ pls.mean() + "\t" + "stddev = " + pls.stddev() + "\t" + "95%% confidence Interval  = ["+
            pls.confidenceLo() +","+ pls.confidenceHi() + "]");

    }
}
