public class Solution
{
    public IList<Interval> Merge(IList<Interval> intervals)
    {
        List<Interval> retList = new List<Interval>();
        retList.AddRange(intervals);

        retList.Sort((a, b) => a.start - b.start);

        int anchor = 1;
        while(anchor < retList.Count)
        {
            if(retList[anchor - 1].end >= retList[anchor].start)
            {
                if (retList[anchor - 1].end < retList[anchor].end)
                    retList[anchor - 1].end = retList[anchor].end;
                retList.RemoveAt(anchor);
            } else
            {
                anchor++;
            }
        }

        return retList;
    }
}
