int numlen(int n)
{
    int len = 0;

    if(n < 0)
        len = 1;
    while(n != 0)
    {
        n /= 10;
        len++;
    }
}

