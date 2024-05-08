#include <stdlib.h>

void    free_arr(char **str)
{
    int i;

    i = 0;
    while(*str[i])
    {
        free(str[i]), i++;
    }
    free(str);
}

int ft_strlin(char *str)
{
    int k;
    k = 0;
    while (str[k] != '\0' && (str[k] != ' ' && str[k] != '\t' && str[k] != '\n'))
        k++;
    return (k);
}


char    **ft_split(char *str)
{
    char **string;
    int i;
    int k;
    int l;
    int len;

    i = 0;
    k = 0;
    if (!str)
        return (NULL);
    string = (char **)malloc(sizeof(char *)  * 100);
    if (!string)
        return (NULL);
    while (i >= 0)
    {
        len = ft_strlin(str + k);
        string[i] = (char *)malloc(sizeof(char) * (len + 1));
        if (!string[i])
            return (free_arr(string), NULL);
        while (str[k] && (str[k] == ' ' || str[k] == '\t' || str[k] == '\n'))
            k++;
        if (str[k] == '\0')
            break ;
        l = 0;
        while (str[k] && (str[k] != ' ' && str[k] != '\t' && str[k] != '\n'))
            string[i][l++] = str[k++];
        string[i][l] = '\0';
        i++;
    }
    string[i] = NULL;
    return (string);
}

