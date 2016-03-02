CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		QuickSort.o

LIBS =

TARGET =	QuickSort

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
