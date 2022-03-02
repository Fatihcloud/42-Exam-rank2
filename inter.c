#include <unistd.h>

int is_in(char c, char *str, int len)
{
	int i = 0;
	while(i < len)
	{
		if(c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int i = 0;
		char *s1 = argv[1];
		char *s2 = argv[2];
		while(s1[i])
		{
			if(!is_in(s1[i], s1, i) && is_in(s1[i], s2, ft_strlen(s2)))
				write(1, &s1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
