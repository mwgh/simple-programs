class Solution {
    public double myPow(double x, int n) {
        if (n == 0 || new Double(x).equals(1.0)) {
            return 1.0;
        } else if (n == 1) {
            return x;
        } else if (n % 2 == 0) {
            double r = myPow(x, n/2);
            return r * r;
        } else if (n > 0) {
            double r = myPow(x, n/2);
            return x * r * r;
        } else {
            double r = myPow(x, -n/2);
            return 1 / (x * r * r);
        }
    }
}
