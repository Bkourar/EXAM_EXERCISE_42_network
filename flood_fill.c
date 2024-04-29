#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void    fill(char **tab, t_point size, t_point cur, char c)
{
    if (cur.y < 0 || cur.y  >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] == 'F' || tab[cur.y][cur.x] == c)
        return ;
    tab[cur.y][cur.x] = 'F';
    fill(tab, size, (t_point){cur.x, cur.y - 1}, c);
    fill(tab, size, (t_point){cur.x, cur.y + 1}, c);
    fill(tab, size, (t_point){cur.x - 1, cur.y}, c);
    fill(tab, size, (t_point){cur.x + 1, cur.y}, c);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
    if (tab[begin.y][begin.x] == '0')
        fill(tab, size, begin, '1');
   else if (tab[begin.y][begin.x] == '1')
        fill(tab, size, begin, '0');
}


char** make_area(char** zone, t_point size)
{
  char** new;

  new = malloc(sizeof(char*) * size.y);
  for (int i = 0; i < size.y; ++i)
  {
    new[i] = malloc(size.x + 1);
    for (int j = 0; j < size.x; ++j)
      new[i][j] = zone[i][j];
    new[i][size.x] = '\0';
  }

  return new;
}

int main(void)
{
  t_point size = {8, 5};
//   char *zone[] = {
//     "11111111",
//     "10001001",
//     "10010001",
//     "10110001",
//     "11100001",
//   };
  char *zone[] = {
    "11111111",
    "10000001",
    "10010101",
    "10110001",
    "11101111",
  };

  char**  area = make_area(zone, size);
  for (int i = 0; i < size.y; ++i)
    printf("%s\n", area[i]);
  printf("\n");
  t_point begin = {7, 4};
  flood_fill(area, size, begin);
  for (int i = 0; i < size.y; ++i)
    printf("%s\n", area[i]);
  return (0);
}