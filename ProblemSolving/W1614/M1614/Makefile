CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = M1614

OBJS = M1614.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
