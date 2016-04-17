CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

TARGET = MH1612 

OBJS = MH1612.o

LIBS =

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
