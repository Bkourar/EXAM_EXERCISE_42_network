int max(int *tab, unsigned int len)
{
    unsigned int    i;
    int swp;

    i = 1;
    swp = tab[0];
    while (i < len)
    {
        if (swp < tab[i])
            swp = tab[i];
        i++;
    }
    return (swp);
}