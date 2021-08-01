int compress(char* chars, int s)
{
    if(s==1)
        return 1;
    char a[s];
    strncpy(a, chars, s);
    int index = 0;
    int sum = 1;
    int i=0;
    for ( i = 1; i < s; i++)
    {
        if (a[i] == a[i - 1])
            sum++;
        else
        {
            chars[index] = chars[i - 1];
            if (sum > 1)
            {
                char text[2000];
                sprintf(text, "%d", sum);
                for (int j = 0; text[j] != '\0'; j++)
                {
                    chars[index + 1] = text[j];
                    index++;
                }
                index++;
            }
            else
            {
                index++;
            }
            sum = 1;
        }
    }
    chars[index] = chars[i - 1];
    if (sum > 1)
    {
        char text[2000];
        sprintf(text, "%d", sum);
        for (int j = 0; text[j] != '\0'; j++)
        {
            chars[index + 1] = text[j];
            index++;
        }
        index++;
    }
    else
    {
        index++;
    }
    return index;
}