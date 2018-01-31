#include <unistd.h>

int	main(void)
{
	write(0, "1\n", 2);
	write(0, "22\n", 3);	
	return (0);
}

