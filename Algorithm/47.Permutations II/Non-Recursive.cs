//Runtime: 485 ms
//Beats 91.67%
//Also work with 46.Permutations I

public class Solution
{
    public IList<IList<int>> PermuteUnique(int[] nums)
    {
        List<IList<int>> ret = new List<IList<int>>();
        Array.Sort(nums);
        ret.Add(nums.ToArray());

        while (true)
        {
            bool exchangeFlag = false;
            for (int i = nums.Length - 1; i >= 0; i--)
            {
                for (int j = nums.Length - 1; j > i; j--)
                {
                    if (nums[j] > nums[i])
                    {
                        exchangeFlag = true;
                        int foo = nums[i];
                        nums[i] = nums[j];
                        nums[j] = foo;
                        Array.Reverse(nums, i + 1, nums.Length - i - 1);
                        ret.Add(nums.ToArray());
                        break;
                    }
                }
                if (exchangeFlag) break;
            }
            if (!exchangeFlag) break;
        }

        return ret;
    }
}
