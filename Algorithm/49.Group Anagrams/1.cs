  public class Solution
  {
      public IList<IList<string>> GroupAnagrams(string[] strs)
      {
          Dictionary<int, IList<string>> retDic = new Dictionary<int, IList<string>>();

          foreach (string str in strs)
          {
              List<int> kList = new List<int>();
              int key = 0;
              foreach (char c in str.ToCharArray())
              {
                  kList.Add(c - 'a' + 1);
              }

              kList.Sort();
              foreach(int k in kList)
              {
                  key *= 31;
                  key += k;
              }

              if (!retDic.ContainsKey(key))
                  retDic.Add(key, new List<string>());
              retDic[key].Add(str);
          }

          var ret = new List<IList<string>>();
          ret.AddRange(retDic.Values.ToArray());
          return ret;
      }
  }
