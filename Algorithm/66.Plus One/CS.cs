//268ms
//beat 100%   ?

public class Solution {
    public int[] PlusOne(int[] digits) {
        for(int i = digits.Length - 1; i >= 0; i--) {
            if(++digits[i] <= 9) break;
            if(i == 0) break;
            digits[i] = 0;
        }
        
        if(digits.Length > 0 && digits[0] > 9) {
            digits[0] = 0;
            var digitsList = new List<int>(digits);
            digitsList.Insert(0, 1);
            return digitsList.ToArray();
        }
        return digits;
    }
}
