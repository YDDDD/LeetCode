//Runtime:565ms
//beats 73.84%
public class Solution
{
    public IList<IList<int>> CombinationSum(int[] candidates, int target)
    {
        List<IList<int>> ret = new List<IList<int>>();          
        Array.Sort(candidates);
        Push(candidates, target, 0, new List<int>(), ret);

        return ret;
    }

    public void Push(int[] candidates, int target, int cursor, List<int> stack, List<IList<int>> ret)
    {
        int sum = stack.Sum();
        for (int i = cursor; i < candidates.Length && candidates[i] <= target && sum + candidates[i] <= target; i++)
        {
            stack.Add(candidates[i]);
            if (sum + candidates[i] == target){
                    ret.Add(stack.ToArray());                    
                stack.RemoveAt(stack.Count - 1);
                break;
            }
            Push(candidates, target, i, stack, ret);
            stack.RemoveAt(stack.Count - 1);
        }
    }
}
