CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = H1615

OBJS = H1615.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
