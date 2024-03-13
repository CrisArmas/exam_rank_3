#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str= "(null)";
	while (*str)
	{
		*len += write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(long long int nbr, int ref, int *len)
{
	char *str = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		*len+= write(1, "-", 1);
	}
	if (nbr >= ref)
		ft_putnbr((nbr / ref), ref, len);
	*len += write(1, &str[nbr % ref], 1);
}
int	ft_printf(const char *format, ...)
{
	int	len = 0;

	va_list pt;
	va_start(pt, format);

	while (*format)
	{
		if((*format == '%') && 
			((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pt, char *), &len);
			else if (*format == 'd')
				ft_putnbr((long long int)va_arg(pt, int), 10, &len);
			else if (*format == 'x')
				ft_putnbr((long long int)va_arg(pt, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(pt), len);
}
