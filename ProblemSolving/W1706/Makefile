CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = MH1706

OBJS = MH1706.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
