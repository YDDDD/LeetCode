//Runtime 538ms..
//Beats 63.57%

public class Solution
{
    public IList<IList<int>> Permute(int[] nums)
    {
        IList<IList<int>> ret = new List<IList<int>>();
        Run(new List<int>(), new List<int>(nums), ret);
        return ret;
    }

    private void Run(List<int> baseline, List<int> candidates, IList<IList<int>> ret)
    {
        for (int i = 0; i < candidates.Count; i++) {
            int candidate = candidates[i];
            baseline.Add(candidate);
            candidates.RemoveAt(i);
            Run(baseline, candidates, ret);
            candidates.Insert(i, candidate);
            baseline.RemoveAt(baseline.Count - 1);
        }
        if (candidates.Count == 0) {
            ret.Add(baseline.ToArray());
        }

    }
}
