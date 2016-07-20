HDRS = $(wildcard *.h)
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
DEPS = $(patsubst %.cpp, %.d, $(SRCS))

TARGET = test
CXX = g++

$(TARGET): $(OBJS)
	$(CXX) -g -o $(TARGET) $(OBJS)

-include $(DEPS)

%.o: %.cpp
	$(CXX) -c -MMD -std=c++11 $<

.PHONY: clean

clean:
	-rm *.o
	-rm *.d
	-rm *.gch
	-rm $(TARGET)
