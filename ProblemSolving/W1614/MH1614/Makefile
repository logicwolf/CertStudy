CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = MH1614

OBJS = MH1614.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
