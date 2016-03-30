#include <iostream>
#include <sys/epoll.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define _EPOLL_TEST_
//#define _POLL_TEST_

using namespace std;

#ifdef _EPOLL_TEST_
struct epoll_event ev, events[1];
#endif

#ifdef _POLL_TEST_
#endif

int main(void)
{
#ifdef _EPOLL_TEST_
    cout << "epoll test" << endl;
    
    int fd_epoll = epoll_create(100);
    if(fd_epoll < 0) cout << "EPOLL create fails" << endl;
    cout << "fd_epoll : " << fd_epoll << endl;
    
    int fd = open("./1.txt", O_RDWR);
    cout << "fd : " << fd << endl;
   
    ev.events = EPOLLIN|EPOLLET;
    ev.data.fd = fd;
    //ev.data.fd = STDIN_FILENO;
    int nRet = epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd, &ev);
    cout << "nRet : " << nRet <<endl;
    
    int ndfs;
    
    while(1)
    {
        ndfs = epoll_wait(fd_epoll, events, 1, -1);
        //if(ndfs < 0) cout << "critical errors occured!!" << endl;
        //cout << "event received" << endl;
    }
#endif

#ifdef _POLL_TEST_
    struct pollfd pollfd[1];
    char buffer[256];
    int fd = open("./1.txt", O_RDWR);
    
#endif
    
    return 0;
}
