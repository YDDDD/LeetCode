//96 ms
//beats 99

public class Solution {
    public string AddBinary(string a, string b) {
        char[] la = a.ToCharArray().Reverse().ToArray(), lb = b.ToCharArray().Reverse().ToArray();
        int length = la.Length > lb.Length ? la.Length : lb.Length;
        bool flag = false;
        var retList = new List<char>();
        for(int i = 0; i < length; i++) {
            int ia = i >= la.Length ? 0 : la[i] - '0', ib = i >= lb.Length ? 0 : lb[i] - '0', digit = ia + ib + (flag? 1 : 0);
            flag = false;
            if(digit >= 2) {
                flag = true;
                digit -= 2;
            }
            retList.Add(Convert.ToChar(digit + '0'));
        }
        
        if(flag) retList.Add('1');
        
        retList.Reverse();
        return new String(retList.ToArray());
    }
}
