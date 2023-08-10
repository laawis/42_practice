// LE BEST EN RÉCURSIF

#include <unistd.h>

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
}
