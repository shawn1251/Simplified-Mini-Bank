
CXX = g++

CXXFLAGS = -Wall -g

TARGET = simple_bank


SOURCES = main.cpp Account.cpp Bank.cpp Teller.cpp TransactionNode.cpp
HEADERS = Account.h Bank.h Teller.h TransactionNode.h

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
