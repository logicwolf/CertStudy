CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = M1615

OBJS = M1615.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
