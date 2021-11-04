class MyPow {
    public static void main(String[] args) {
        MyPow s = new MyPow();
        testMyPow(s, -2.0, 3);
        testMyPow(s, 2.0, 3);
    }

    private static double testMyPow(MyPow s, double x, int n) {
        double myPow = s.myPow(x, n);
        assert(myPow == Math.pow(x, n));
        System.out.println(x + "^" + n + " = " + myPow);
        return myPow;
    }

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
