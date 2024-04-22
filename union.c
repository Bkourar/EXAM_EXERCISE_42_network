#include <unistd.h>
#include <stdio.h>

int check(char *str , char c)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    int i = -1;
    int j = 0;
    char    t[1024];
    
    while (av[1][++i])
    {
        if (!check(av[2], av[1][i]))
        {
            t[j++] = av[1][i];
            if (!check(t, av[1][i]))
                t[j++] = av[1][i];
        }
        if (!check(t, av[1][i]))
            t[j++] = av[1][i];
    }
    i = -1;
    while (av[2][++i])
    {
        if (!check(t, av[2][i]))
            t[j++] = av[2][i];
    }
    puts(t);
    return 0;
}