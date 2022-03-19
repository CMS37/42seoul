/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:30:14 by min-cho           #+#    #+#             */
/*   Updated: 2022/01/15 00:30:14 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	nbr;
	int		m;
	int		i;

	nbr = 0;
	i = 0;
	m = 1;
	while (white_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
		m *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nbr *= 10;
		nbr += (nptr[i] - '0');
		if (nbr > 2147483647 && m == 1)
			return (-1);
		if (nbr > 2147483648 && m == -1)
			return (0);
		i++;
		if (nptr[i] < '0' || nptr[i] > '9')
			break ;
	}
	return (nbr * m);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("a int max 2147483647 : %d\n", atoi("2147483647"));
//     printf("f int max 2147483647 : %d\n", ft_atoi("2147483647"));
//     printf("a int min -2147483648 : %d\n", atoi("-2147483648"));
//     printf("f int min -2147483648 : %d\n", ft_atoi("-2147483648"));
//     printf("a int over 9999999999 : %d\n", atoi("9999999999"));
//     printf("f int over 9999999999 : %d\n", ft_atoi("9999999999"));
//     printf("a int under -9999999999 : %d\n", atoi("-9999999999"));
//     printf("f int under -9999999999 : %d\n", ft_atoi("-9999999999"));
//     printf("a long long plus 92233720368547758 : %d\n", atoi("92233720368547758"));
//     printf("f long long plus 92233720368547758 : %d\n", ft_atoi("92233720368547758"));
//     printf("a long long minus -92233720368547758 : %d\n", atoi("-92233720368547758"));
//     printf("f long long minus -92233720368547758 : %d\n", ft_atoi("-92233720368547758"));
//     printf("a long long max 9223372036854775807 : %d\n", atoi("9223372036854775807"));
//     printf("f long long max 9223372036854775807 : %d\n", ft_atoi("9223372036854775807"));
//     printf("a long long min -9223372036854775808 : %d\n", atoi("–9223372036854775808"));
//     printf("f long long min -9223372036854775808 : %d\n", ft_atoi("–9223372036854775808"));
//     printf("a long long max / 10 922337203685477580 : %d\n", atoi("922337203685477580"));
//     printf("f long long max / 10 922337203685477580 : %d\n", ft_atoi("922337203685477580"));
//     printf("a long long max / 10 + 1 922337203685477581 : %d\n", atoi("922337203685477581"));
//     printf("f long long max / 10 + 1 922337203685477581 : %d\n", ft_atoi("922337203685477581"));
//     printf("a long long max / 10 + 4 922337203685477584 : %d\n", atoi("922337203685477584"));
//     printf("f long long max / 10 + 4 922337203685477584 : %d\n", ft_atoi("922337203685477584"));
//     printf("a long long max / 10 + 5 922337203685477585 : %d\n", atoi("922337203685477585"));
//     printf("f long long max / 10 + 5 922337203685477585 : %d\n", ft_atoi("922337203685477585"));
//     printf("a long long max - 1 922337203685477586 : %d\n", atoi("922337203685477586"));
//     printf("f long long max - 1 922337203685477586 : %d\n", ft_atoi("922337203685477586"));
//     printf("a long long max + 1 9223372036854775808 : %d\n", atoi("9223372036854775808"));
//     printf("f long long max + 1 9223372036854775808 : %d\n", ft_atoi("9223372036854775808"));
//     printf("a long long max + 2 9223372036854775809 : %d\n", atoi("9223372036854775809"));
//     printf("f long long max + 2 9223372036854775809 : %d\n", ft_atoi("9223372036854775809"));
//     printf("a long long max + 10 9223372036854775817 : %d\n", atoi("9223372036854775817"));
//     printf("f long long max + 10 9223372036854775817 : %d\n", ft_atoi("9223372036854775817"));
//     printf("a long long min - 1 –9223372036854775809 : %d\n", atoi("–9223372036854775809"));
//     printf("f long long min - 1 –9223372036854775809 : %d\n", ft_atoi("–9223372036854775809"));
//     printf("a long long min - 2 –9223372036854775810 : %d\n", atoi("–9223372036854775810"));
//     printf("f long long min - 2 –9223372036854775810 : %d\n", ft_atoi("–9223372036854775810"));
//     printf("a long long min - 10 –9223372036854775818 : %d\n", atoi("–9223372036854775818"));
//     printf("f long long min - 10 –9223372036854775818 : %d\n", ft_atoi("–9223372036854775818"));
//     printf("a long long over 9223379876854775807 : %d\n", atoi("9223379876854775807"));
//     printf("f long long over 9223379876854775807 : %d\n", ft_atoi("9223379876854775807"));
//     printf("a long long under -9223379876854775807 : %d\n", atoi("-9223379876854775807"));
//     printf("f long long under -9223379876854775807 : %d\n", ft_atoi("-9223379876854775807"));
//     printf("a long long half 4611686018427387903 : %d\n", atoi("4611686018427387903"));
//     printf("f long long half 4611686018427387903 : %d\n", ft_atoi("4611686018427387903"));
//     printf("a zero 0 : %d\n", atoi("0"));
//     printf("f zero 0 : %d\n", ft_atoi("0"));
//     printf("a empty  : %d\n", atoi(""));
//     printf("f empty  : %d\n", ft_atoi(""));
//     return (0);
// }

// /*
//     { "1011101100",   1011101100   },
//     { "1234567",         1234567   },
//     { "-214",               -214   },
//     { "+214",                214   }, /* The + sign is allowed also */
//     { "--214",                 0   }, /* Do not accept more than one sign */
//     { "-+214",                 0   },
//     { "++214",                 0   },
//     { "+-214",                 0   },
//     { "\00141",                0   }, /* not whitespace char  1 */
//     { "\00242",                0   }, /* not whitespace char  2 */
//     { "\00343",                0   }, /* not whitespace char  3 */
//     { "\00444",                0   }, /* not whitespace char  4 */
//     { "\00545",                0   }, /* not whitespace char  5 */
//     { "\00646",                0   }, /* not whitespace char  6 */
//     { "\00747",                0   }, /* not whitespace char  7 */
//     { "\01050",                0   }, /* not whitespace char  8 */
//     { "\01151",               51   }, /*  is whitespace char  9 (tab) */
//     { "\01252",               52   }, /*  is whitespace char 10 (lf) */
//     { "\01353",               53   }, /*  is whitespace char 11 (vt) */
//     { "\01454",               54   }, /*  is whitespace char 12 (ff) */
//     { "\01555",               55   }, /*  is whitespace char 13 (cr) */
//     { "\01656",                0   }, /* not whitespace char 14 */
//     { "\01757",                0   }, /* not whitespace char 15 */
//     { "\02060",                0   }, /* not whitespace char 16 */
//     { "\02161",                0   }, /* not whitespace char 17 */
//     { "\02262",                0   }, /* not whitespace char 18 */
//     { "\02363",                0   }, /* not whitespace char 19 */
//     { "\02464",                0   }, /* not whitespace char 20 */
//     { "\02565",                0   }, /* not whitespace char 21 */
//     { "\02666",                0   }, /* not whitespace char 22 */
//     { "\02767",                0   }, /* not whitespace char 23 */
//     { "\03070",                0   }, /* not whitespace char 24 */
//     { "\03171",                0   }, /* not whitespace char 25 */
//     { "\03272",                0   }, /* not whitespace char 26 */
//     { "\03373",                0   }, /* not whitespace char 27 */
//     { "\03474",                0   }, /* not whitespace char 28 */
//     { "\03575",                0   }, /* not whitespace char 29 */
//     { "\03676",                0   }, /* not whitespace char 30 */
//     { "\03777",                0   }, /* not whitespace char 31 */
//     { "\04080",               80   }, /*  is whitespace char 32 (space) */
//     { " \n \r \t214",        214   },
//     { " \n \r \t+214",       214   }, /* Signs can be used after whitespace */
//     { " \n \r \t-214",      -214   },
//     { "+214 0",              214   }, /* Space terminates the number */
//     { " 214.01",             214   }, /* Decimal point not accepted */
//     { " 214,01",             214   }, /* Decimal comma not accepted */
//     { "f81",                   0   },
//     { "0x12345",               0   }, /* Hex not accepted */
//     { "00x12345",              0   },
//     { "0xx12345",              0   },
//     { "1x34",                  1   },
//     { "-9999999999", -1410065407   }, /* Big negative integer */
//     { "-2147483649",  2147483647   }, /* Too small to fit in 32 Bits */
//     { "-2147483648",  0x80000000   }, /* Smallest negative integer */
//     { "-2147483647", -2147483647   },
//     { "-1",                   -1   },
//     { "0",                     0   },
//     { "1",                     1   },
//     { "2147483646",   2147483646   },
//     { "2147483647",   2147483647   }, /* Largest signed positive integer */
//     { "2147483648",   2147483648UL }, /* Positive int equal to smallest negative int */
//     { "2147483649",   2147483649UL },
//     { "4294967294",   4294967294UL },
//     { "4294967295",   4294967295UL }, /* Largest unsigned integer */
//     { "4294967296",            0   }, /* Too big to fit in 32 Bits */
//     { "9999999999",   1410065407   }, /* Big positive integer */
//     { "056789",            56789   }, /* Leading zero and still decimal */
//     { "b1011101100",           0   }, /* Binary (b-notation) */
//     { "-b1011101100",          0   }, /* Negative Binary (b-notation) */
//     { "b10123456789",          0   }, /* Binary with nonbinary digits (2-9) */
//     { "0b1011101100",          0   }, /* Binary (0b-notation) */
//     { "-0b1011101100",         0   }, /* Negative binary (0b-notation) */
//     { "0b10123456789",         0   }, /* Binary with nonbinary digits (2-9) */
//     { "-0b10123456789",        0   }, /* Negative binary with nonbinary digits (2-9) */
//     { "0b1",                   0   }, /* one digit binary */
//     { "0b2",                   0   }, /* empty binary */
//     { "0b",                    0   }, /* empty binary */
//     { "o1234567",              0   }, /* Octal (o-notation) */
//     { "-o1234567",             0   }, /* Negative Octal (o-notation) */
//     { "o56789",                0   }, /* Octal with nonoctal digits (8 and 9) */
//     { "0o1234567",             0   }, /* Octal (0o-notation) */
//     { "-0o1234567",            0   }, /* Negative octal (0o-notation) */
//     { "0o56789",               0   }, /* Octal with nonoctal digits (8 and 9) */
//     { "-0o56789",              0   }, /* Negative octal with nonoctal digits (8 and 9) */
//     { "0o7",                   0   }, /* one digit octal */
//     { "0o8",                   0   }, /* empty octal */
//     { "0o",                    0   }, /* empty octal */
//     { "0d1011101100",          0   }, /* explizit decimal with 0d */
//     { "x89abcdef",             0   }, /* Hex with lower case digits a-f (x-notation) */
//     { "xFEDCBA00",             0   }, /* Hex with upper case digits A-F (x-notation) */
//     { "-xFEDCBA00",            0   }, /* Negative Hexadecimal (x-notation) */
//     { "0x89abcdef",            0   }, /* Hex with lower case digits a-f (0x-notation) */
//     { "0xFEDCBA00",            0   }, /* Hex with upper case digits A-F (0x-notation) */
//     { "-0xFEDCBA00",           0   }, /* Negative Hexadecimal (0x-notation) */
//     { "0xabcdefgh",            0   }, /* Hex with illegal lower case digits (g-z) */
//     { "0xABCDEFGH",            0   }, /* Hex with illegal upper case digits (G-Z) */
//     { "0xF",                   0   }, /* one digit hexadecimal */
//     { "0xG",                   0   }, /* empty hexadecimal */
//     { "0x",                    0   }, /* empty hexadecimal */
//     { "",                      0   }, /* empty string */
// /*  { NULL,                    0   }, */ /* NULL as string */
// */