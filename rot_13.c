#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	while (av[1][i])
	{
		if (av[1][i] >= 65 && av[1][i] <= 90)
		{
			if (av[1][i] >= 65 && av[1][i] <= 77)
				av[1][i] += 13;
			else
				av[1][i] -= 13;
		}
		else if (av[1][i] >= 97 && av[1][i] <= 122)
		{
			if (av[1][i] >= 97 && av[1][i] <= 109)
				av[1][i] += 13;
			else 
				av[1][i] -= 13;
		}
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}