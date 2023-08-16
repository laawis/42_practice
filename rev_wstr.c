#include <unistd.h>

// LE MIEN
// return_code est seulement pour la nouvelle version de gcc où il faut gérer le retour de write.

int    get_last_word(char *s, int index)
{
    int    i;
    int    return_code;

    i = 0;
    while (index > 0 && (s[index] == '\0' || s[index] == ' ' || s[index] == '\t'))
    {
        index--;
        i++;
    }
    while (index >= 0 && s[index] != ' ' && s[index] != '\t')
    {
        index--;
        i++;
    }
    index++;
    while (s[index] != '\0' && s[index] != ' ' && s[index] != '\t')
    {
        return_code = write(1, &s[index], 1);
        (void) return_code;
        index++;
    }
    return (i);
}

int    main(int argc, char **argv)
{
    int    i;
    int    return_code;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
            i++;
        while (i >= 0)
        {
            i -= get_last_word(argv[1], i);
            while (i > 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
                i--;
            if (i == 0)
            {
                return_code = write(1, "\n", 1);
                (void) return_code;
                return (0);
            }
            else
            {
                return_code = write(1, " ", 1);
                (void) return_code;
            }
        }
    }
    return_code = write(1, "\n", 1);
    (void) return_code;
    return (0);
}



// LE PETIT FRÈRE EN ITÉRATIF

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
		
	if(argc == 2)
	{   
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			int  flag;
			flag = start;
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
			if (flag !=0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

// LE RÉCURSIF

void		rev_wstr(char *s, int first)
{
	int		start;
	int		i;

	i = 0;
	if (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (!s[i])
			return ;
		start = i;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
		rev_wstr(&s[i], 0);
		write(1, &s[start], i - start);
		if (!first)
			write(1, " ", 1);
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1], 1);
	write(1, "\n", 1);
	return (0);
}
/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
