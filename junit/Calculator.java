class Calculator {
    public int add(int ...arr) {
        int sum = 0;
        for (int i : arr)
            sum += i;
        return sum;
    }
}
