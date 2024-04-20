#include <unistd.h>

size_t	ft_strspn(char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	while (s2[i])
	{
		while (s2[i] && s2[i] == ' ')
			i++;
		j = 0;
		while (s1[j] && s1[j] == s2[i])
		{
			j++;
            i++;
		}
		if (j != 0)
			return (j);
		i++;
	}
	return (0);
}
