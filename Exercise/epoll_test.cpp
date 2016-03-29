#include <iostream>
#include <sys/epoll.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

struct epoll_event ev, events[1];

int main(void)
{
    cout << "epoll test" << endl;
    
    int fd_epoll = epoll_create(1);
    if(fd_epoll < 0) cout << "EPOLL create fails" << endl;
    cout << "fd_epoll : " << fd_epoll << endl;
    
    int fd = open("1.txt", O_RDWR);
    cout << "fd : " << fd << endl;
   
    ev.events = EPOLLIN;
    ev.data.fd = fd;
    
    epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd, &ev);
    
    int ndfs;
    
    while(1)
    {
        ndfs = epoll_wait(fd_epoll, events, 1, -1);
        if(ndfs < 0) cout << "critical errors occured!!" << endl;
        cout << "event received" << endl;
    }
    
    return 0;
}
