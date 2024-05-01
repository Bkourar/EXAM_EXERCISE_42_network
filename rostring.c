#include <unistd.h>

void	ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int main(int ac, char **av)
{
    int     i;
    int     j;
    char    stack[1024];
    
    i = 0;
    j = 0;
    if (ac < 2)
        return (write(1, "\n", 1), 1);
    while (av[1][i] && av[1][i] == ' ' || av[1][i] == '\t')
        i++;
    while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
        stack[j++] = av[1][i++];
    stack[j] = '\0';
    while (av[1][i] && av[1][i] == ' ' || av[1][i] == '\t')
        i++;
    if (!av[1][i])
        return (ft_putstr(stack), write(1, "\n", 1), 0);
    while (av[1][i])
    {
        if (av[1][i] != ' ' && av[1][i] != '\t')
            write(1, &av[1][i], 1);
        else if (av[1][i + 1] == '\0' && (av[1][i] == ' ' || av[1][i] == '\t'))
            break ;
        else if (((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i + 1] != ' ' && av[1][i + 1] != '\t'))
            write(1, &av[1][i], 1);
        i++;
    }
    write(1, " ", 1), ft_putstr(stack), write(1, "\n", 1);
}