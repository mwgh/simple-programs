import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

/**
 * Models multiple independent trials of Percolation.
 *
 * @author Mary Wang
 * Date created: 2017 Aug 5
 * Date last updated: 2021 Sept 27
 */
public class PercolationStats {
    private static final double CONFIDENCE_95 = 1.96;
    private final int mT; // number of trials
    private final double[] percolationThreshold; // percolation threshold trials

    /** Performs trials of independent experiments on an n-by-n grid. */
    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) {
            throw new IllegalArgumentException("Grid size n or trial number must be positive");
        }

        this.mT = trials;
        this.percolationThreshold = new double[trials];

        for (int i = 0; i < this.mT; i++) {
            Percolation perc = new Percolation(n);
            // do independent experiments
            while (!perc.percolates()) {
                int x = StdRandom.uniform(n) + 1;
                int y = StdRandom.uniform(n) + 1;

                perc.open(x, y);
            }
            this.percolationThreshold[i] = ((double) perc.numberOfOpenSites()) / (n * n);
        }
    }

    /** Returns the sample mean of the percolation trials. */
    public double mean() {
        return StdStats.mean(percolationThreshold);
    }

    /** Returns the sample standard deviation of the percolation trials. */
    public double stddev() {
        // return Double.NaN if 1 trial?
        return StdStats.stddev(percolationThreshold);
    }

    /** Returns the low endpoint of the 95% confidence interval. */
    public double confidenceLo() {
        return mean() - (CONFIDENCE_95 * stddev()) / Math.sqrt(this.mT);
    }

    /** Returns the high endpoint of the 95% confidence interval. */
    public double confidenceHi() {
        return mean() + (CONFIDENCE_95 * stddev()) / Math.sqrt(this.mT);
    }

    /** Executes the test client (described below). */
    public static void main(String[] args) {
        PercolationStats ps = new PercolationStats(Integer.parseInt(args[0]), Integer.parseInt(args[1]));

        System.out.println("mean                    = " + ps.mean());
        System.out.println("stddev                  = " + ps.stddev());
        System.out.println("95% confidence interval = [" + ps.confidenceLo() + ", " + ps.confidenceHi() + "]");
    }
}
