import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import edu.princeton.cs.algs4.StdRandom;

/**
 * Models a percolation system.
 *
 * @author Mary Wang
 * Date created: 2017 Aug 5
 * Date last updated: 2021 Sept 27
 */
public class Percolation {
    private final int mN; // row and column size
    private final int mSize; // grid size
    private int openSites; // number of open sites
    private CellStatus[] site; // keep track of blocked, open, and full sites
    private final WeightedQuickUnionUF ufA; // percolation union-find
    
    private enum CellStatus {
        BLOCKED,
        OPEN,
        FULL
    }

    /** Creates an n-by-n grid with all sites blocked. */
    public Percolation(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("Size must be positive");
        }
        mN = n;
        mSize = mN * mN;
        ufA = new WeightedQuickUnionUF(mSize + 1);

        // add one to create an extra site on the top
        site = new CellStatus[mSize + 1];

        for (int i = 0; i < mSize; i++) {
            site[i] = CellStatus.BLOCKED;
        }

        // mSize is the index of the extra site on the top
        site[mSize] = CellStatus.FULL;
    }

    /** Opens the site (row, col) if it is not open already. */
    public void open(int row, int col) {
        validate(row, col);
        if (isOpen(row, col)) {
            return;
        }

        site[xyTo1D(row, col)] = CellStatus.OPEN;
        openSites++;
        unionSurroundingOpenSites(row, col);

        fill(row, col);
    }
    
    private void fill(int row, int col) {
        if (!isOpen(row, col)) {
            assert false : "We shouldn't try to fill sites that are BLOCKED.";
        }

        // If we can fill this site, fill it
        // and recursively fill the neighbouring open sites.
        boolean isCellInTopRow = row == 1;
        boolean isNeighbourFull = isNeighbourFull(row, col);
        if (isCellInTopRow || isNeighbourFull) {
            site[xyTo1D(row, col)] = CellStatus.FULL;

            // not left edge
            if (col != 1 && isOpen(row, col - 1) && !isFull(row, col - 1)) {
                fill(row, col - 1);
            }

            // not right edge
            if (col != mN && isOpen(row, col + 1) && !isFull(row, col + 1)) {
                fill(row, col + 1);
            }

            // not top edge
            if (row != 1 && isOpen(row - 1, col) && !isFull(row - 1, col)) {
                fill(row - 1, col);
            }

            // not bottom edge
            if (row != mN && isOpen(row + 1, col) && !isFull(row + 1, col)) {
                fill(row + 1, col);
            }
        }
    }
    
    private boolean isNeighbourFull(int row, int col) {
        boolean isNeighbourFull = false;
        
        // not left edge
        if (col != 1) {
            isNeighbourFull |= isFull(row, col - 1);
        }

        // not right edge
        if (col != mN) {
            isNeighbourFull |= isFull(row, col + 1);
        }

        // not top edge
        if (row != 1) {
            isNeighbourFull |= isFull(row - 1, col);
        }

        // not bottom edge
        if (row != mN) {
            isNeighbourFull |= isFull(row + 1, col);
        }
        
        return isNeighbourFull;
    }

    /** Unions the open site (row, col) with any surrounding open sites. */
    private void unionSurroundingOpenSites(int row, int col) {
        int i = xyTo1D(row, col);

        // not left edge
        if (col != 1) {
            unionOpen(i, i - 1);
        }

        // not right edge
        if (col != mN) {
            unionOpen(i, i + 1);
        }

        // not top edge
        if (row != 1) {
            unionOpen(i, i - mN);
        } else {
            // union the site (row, col) with the virtual top site
            ufA.union(i, mSize);
        }

        // not bottom edge
        if (row != mN) {
            unionOpen(i, i + mN);
        }
    }

    private void unionOpen(int i, int next) {
        if (site[next] == CellStatus.OPEN && (ufA.find(i) != ufA.find(next))) {
            ufA.union(i, next);
        }
    }

    /** Converts a (row, col) address to an array index. */
    private int xyTo1D(int row, int col) {
        // validate(row, col); // could be unneccessary
        return ((row - 1) * mN) + col - 1;
    }

    /** Returns if the site (row, col) is open. */
    public boolean isOpen(int row, int col) {
        validate(row, col);
        return site[xyTo1D(row, col)] != CellStatus.BLOCKED;
    }

    /** Returns if the site (row, col) is full. */
    public boolean isFull(int row, int col) {
        validate(row, col);
        return site[xyTo1D(row, col)] == CellStatus.FULL;
    }

    /** Returns the number of open sites. */
    public int numberOfOpenSites() {
        return openSites;
    }

    /** Returns if the system percolates (there is a full site in the bottom row). */
    public boolean percolates() {
        for (int x = 1; x <= mN; x++) {
            if (isFull(mN, x)) {
                return true;
            }
        }
        return false;
    }
    
    private void validate(int row, int col) {
        if (row <= 0 || row > mN || col <= 0 || col > mN) {
            throw new IllegalArgumentException("Argument out of bounds"); 
        }
    }

    /** Executes the test client (optional). */
    public static void main(String[] args) {
        // Initialize all sites to be blocked
        Percolation p = new Percolation(5);

        while (!p.percolates()) {
            // choose a site uniformly at random among all _blocked sites_
            int x = StdRandom.uniform(p.mN) + 1;
            int y = StdRandom.uniform(p.mN) + 1;

            // open the site
            p.open(x, y);
        }

        // fraction of open sites is estimated percolation threshold
        System.out.println("The number of open sites is " + p.numberOfOpenSites());
        System.out.println("The fraction of open sites is " + ((double) p.numberOfOpenSites()) / (p.mSize));
    }
}
