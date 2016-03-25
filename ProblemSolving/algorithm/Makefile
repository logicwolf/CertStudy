CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		DFS.o

LIBS =

TARGET =	DFS

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
