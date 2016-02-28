CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

MAIN_NAME = MH1607

OBJS =		$(MAIN_NAME).o

LIBS =

TARGET =	$(MAIN_NAME)

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
