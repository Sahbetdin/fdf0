
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int get_next_line(int fd, char **line);

int main()
{
    int fd;
    char *line;

    fd = open("t.txt", O_RDONLY);
    get_next_line(fd, &line);

    free(line);

    close(fd);
}