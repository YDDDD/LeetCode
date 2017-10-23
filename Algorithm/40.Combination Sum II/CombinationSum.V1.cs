//Runtime: 549 ms
//Beats 86.84%

public class Solution
{
    public IList<IList<int>> CombinationSum2(int[] candidates, int target)
    {
        Dictionary<int, IList<int>> ret = new Dictionary<int, IList<int>>();
        Array.Sort(candidates);
        Push(candidates, target, 0, new List<int>(), ret);

        return ret.Values.ToList();
    }

    public void Push(int[] candidates, int target, int cursor, List<int> stack, Dictionary<int, IList<int>> ret)
    {
        int sum = stack.Sum();
        for (int i = cursor; i < candidates.Length && candidates[i] <= target && sum + candidates[i] <= target; i++)
        {
            stack.Add(candidates[i]);
            if (sum + candidates[i] == target){
                int key = stack.ToArray().Sum(s => s * s * s * s);
                if(!ret.ContainsKey(key))
                    ret.Add(key, stack.ToArray());                    
                stack.RemoveAt(stack.Count - 1);
                break;
            }
            Push(candidates, target, i + 1, stack, ret);
            stack.RemoveAt(stack.Count - 1);
        }
    }
}
