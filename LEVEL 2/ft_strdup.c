//Assignment name  : ft_strdup
//Expected files   : ft_strdup.c
//Allowed functions: malloc
//--------------------------------------------------------------------------------
//Reproduce the behavior of the function strdup (man strdup).
//Your function must be declared as follows:
//char    *ft_strdup(char *src);


char    *ft_strdup(char *src)
{ 
    char *dest;
    int i = 0;

    while (src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

//The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to
//the function free(3).
//If insufficient memory is available, NULL is returned and errno is set to ENOMEM.