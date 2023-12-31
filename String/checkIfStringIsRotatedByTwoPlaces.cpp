bool isRotated(string str1, string str2)
{
    bool clockWise = true;
    bool anticlockWise = true;
    int n = str1.length();
    int m = str2.length();
    if (n != m)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (str2[i] != str1[(i + 2) % n])
        {
            clockWise = false;
        }
    }
    if (clockWise)
        return clockWise;

    for (int i = 0; i < n; i++)
    {
        if (str2[i] != str1[(i - 2 + n) % n])
        {
            anticlockWise = false;
        }
    }
    return anticlockWise;
}