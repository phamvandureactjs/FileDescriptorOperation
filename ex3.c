#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//Step 2
void main(){

struct pollfd struct_fds[2];
int fd;

//Step 3

fd = open("Documents/file1", O_RDONLY);
struct_fds[0].fd = fd;
fd = open("Documents/file2", O_RDONLY);
struct_fds[1].fd = fd;

//Step 4

struct_fds[0].events = POLLOUT;
struct_fds[1].events = POLLOUT;

//Step 5

poll( struct_fds, 2, 0);

if ( struct_fds[0].revents ==  POLLOUT)
     printf("The file1 can accept write operations.\n");
else
    {
     printf("The file1 cannot accept write operations.\n" );
     printf("file1 revents = %i\n", struct_fds[0].revents );
     }
if ( struct_fds[1].revents == POLLOUT)
     printf("The file2 can accept write operations.\n" );
else
    {
     printf("The file2 cannot accept write operations.\n" );
     printf("file2 revents = %i\n", struct_fds[1].revents );
    }
//Step 6
sleep (15);
close (struct_fds[0].fd);
close (struct_fds[1].fd);

}