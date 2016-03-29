CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		epoll_test.o

LIBS =

TARGET =	epoll_test

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
