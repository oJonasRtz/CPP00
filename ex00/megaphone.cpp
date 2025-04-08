#include <iostream>

static void	draw_char(const char c)
{
	std::cout << c;
}

static int	draw_message(const char *str)
{
	if (!str)
		return (0);
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '\\')
			switch (str[++i])
			{
				case 'n': draw_char('\n'); break;
				case 't': draw_char('\t'); break;
				case 'b': draw_char('\b'); break;
				case 'v': draw_char('\v'); break;
				case 'f': draw_char('\f'); break;
				case 'a': draw_char('\a'); break;
				case 'r': draw_char('\r'); break;
				case '\\': draw_char('\\'); break;
			}
		else
			draw_char((char)std::toupper(str[i]));
	}
	return (0);
}

static int	megaphone(int argc, char **argv)
{
	int	i = 0;

	if (argc == 1)
		return (draw_message("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"));
	while (argv[i])
		draw_message(argv[i++]);
	draw_char('\n');
	return (0);
}

int	main(int argc, char **argv)
{
	return (megaphone(argc, ++argv));
}
