import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class ThreeSum {
    public static void main(String[] args) {
        List<List<Integer>> result = 
                new ThreeSum().threeSum(new int[] {-2, 0, 2, 3});
        System.out.println(result);
    }

    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> sumZero = new HashSet<>();

        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            int j = i + 1;
            int k = nums.length - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) --k;
                else if (sum < 0) ++j;
                else sumZero.add(Arrays.asList(nums[i], nums[j++], nums[k--]));
            }
        }
        return new ArrayList<>(sumZero);
    }
}
