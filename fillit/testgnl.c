#include "libft/libft.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;

    char    *line;
    fd = open("truc", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        ft_putstr(line);
    }
    get_next_line(fd, &line);
    ft_putstr(line);
    return (0);
}