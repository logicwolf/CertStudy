CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = SquareSum

OBJS = SquareSum.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
