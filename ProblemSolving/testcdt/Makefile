CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		testcdt.o

LIBS =

TARGET =	testcdt

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
