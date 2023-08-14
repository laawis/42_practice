#include "flood_fill.h"

// déclarer une structure sur une seule ligne sans avoir à déclarer une nouvelle variable:
//(t_struct){nom_struct.nom_du_champ, nom_struct.nom_du_champ};
//(type_struct){nom_struct->champ};

void  flood_fill(char **tab, t_point size, t_point begin)
{
    int    tmp;

    if (begin.x < 0 || begin.y < 0 || begin.x > size.x - 1 || begin.y > size.y - 1)
        return ;
    tmp = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'F';
    if (begin.y - 1 >= 0 && tmp == tab[begin.y - 1][begin.x])
        flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
    if (begin.y + 1 < size.y && tmp == tab[begin.y + 1][begin.x])
        flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
    if (begin.x - 1 >= 0 && tmp == tab[begin.y][begin.x - 1])
        flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
    if (begin.x + 1 < size.x && tmp == tab[begin.y][begin.x + 1])
        flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
}

#include <stdlib.h>
#include <stdio.h>

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
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
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
/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------
Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

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
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
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

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$>
*/
