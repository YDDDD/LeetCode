//Runtime:545ms
//beats 86.63%
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
            if(target < 0) return;
            for (int i = cursor; i < candidates.Length && candidates[i] <= target; i++)
            {
                stack.Add(candidates[i]);
                if (candidates[i] == target)
                    ret.Add(stack.ToArray());                    
                else
                    Push(candidates, target - candidates[i], i, stack, ret);
                stack.RemoveAt(stack.Count - 1);
            }
        }
    }
