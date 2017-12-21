//Runtime:53ms
//100%...

public class Solution {
    public int[,] GenerateMatrix(int n)
    {
        int[,] ret = new int[n, n];

        int top = 1, buttom = n - 1, left = 0, right = n - 1, index = 0, posX = -1, posY = 0, size = n * n;
        while (index < size)
        {
            while (++posX <= right && index < size)
                ret[posY, posX] = ++index;
            right--; posX--;
            while (++posY <= buttom && index < size)
                ret[posY, posX] = ++index;
            buttom--; posY--;
            while (--posX >= left && index < size)
                ret[posY, posX] = ++index;
            left++; posX++;
            while (--posY >= top && index < size)
                ret[posY, posX] = ++index;
            top++; posY++;
        }

        return ret;
    }
}
