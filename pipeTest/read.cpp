#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF
int main()
{
    int pipe_fd;
    char buffer[BUFFER_SIZE + 1];
    //reset all bytes in buffer as '\0' 
    memset(buffer, '\0', sizeof(buffer));
    //open FIFO pipe file.
    //this will be brocked until some one open another end point(write-point) of this pipe
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    if(read(pipe_fd, buffer, BUFFER_SIZE) > 0)
    {
        printf("data from FIFO : %s\n", buffer);
    }
    //close pipe file descriptor
    close(pipe_fd);
    pipe_fd = open(FIFO_NAME, O_WRONLY);

    write(pipe_fd, "hello woshi client", PIPE_BUF);
    close(pipe_fd);
    return 0;
}