#include <unistd.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int ft_putstr(char *str)
{
    return (write(1, str, ft_strlen(str)));
}

int ft_setprint(long number, char *set, int numset)
{
	int i = 0;
	int len = 0;
	if(number == -2147483648)
		return (ft_putstr("-2147483648"));
	if(number < 0)
	{
		len += write(1, "-", 1);
		number = number * -1;
	}
	if(number > numset - 1)
		len += ft_setprint(number/numset, set, numset);
	len += write(1, &set[number%numset], 1);
	return (len);
}

int arg_printer(va_list macro, char c)
{
	if(c == 's')
		return(ft_putstr(va_arg(macro, char *)));
	if (c == 'd')
		return (ft_setprint(va_arg(macro, int), "0123456789", 10));
	if (c == 'x')
		return (ft_setprint(va_arg(macro, unsigned int), "0123456789abcdef", 16));
    return (0);
}
int ft_printf(char *str, ...)
{
	va_list macro;
	int i = 0;
	int len = 0;

	va_start(macro, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			len += arg_printer(macro, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(macro);
	return (len);
}

int main()
{
	ft_printf("uzunluk => %d\n", ft_printf("%s%d%x", "selam", 42, 127));
}
