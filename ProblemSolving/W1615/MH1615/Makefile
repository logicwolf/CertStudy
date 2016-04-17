CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = MH1615

OBJS = MH1615.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
