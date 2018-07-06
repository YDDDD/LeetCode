//88ms
//beats 100%

public class Solution {
    public int TotalPermutationCount(int n) {
        int ret = 1;
        for(int i = 2; i <= n; i++)
            ret *= i;
        return ret;
    }
    
    public void Recursive(List<int> taken, List<int> toTake, int reminds) {
        if(toTake.Count == 1) {
            taken.Add(toTake[0]);
            return;
        }
        
        int permOfTakes = TotalPermutationCount(toTake.Count - 1);
        int index = reminds / permOfTakes;
        
        taken.Add(toTake[index]);
        toTake.RemoveAt(index);
        
        Recursive(taken, toTake, reminds % permOfTakes);
    }
    
    public string GetPermutation(int n, int k) {
        List<int> toTake = new List<int>(), taken = new List<int>();
        for (int i = 1; i <= n; i++)
            toTake.Add(i);

        Recursive(taken, toTake, k - 1);

        var sb = new StringBuilder();
        foreach (var num in taken)
            sb.Append(num.ToString());

        return sb.ToString();
    }
}
