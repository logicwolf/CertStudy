CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		M1607.o

LIBS =

TARGET =	M1607

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
