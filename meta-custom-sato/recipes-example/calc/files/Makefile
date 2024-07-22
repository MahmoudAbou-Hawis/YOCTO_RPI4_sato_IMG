SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

INC = .


CFLAGS = 

TARGET = my_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(CFLAGS) -I $(INC) $(LDFLAGS)


%.o:%.cpp
	$(CXX) $< -c $@ $(CFLAGS)  -I $(INC)


install:
	install -d $(DESTDIR)
	install -m 0755 $(TARGET) $(DESTDIR)

clean:
	rm  -f $(TARGET)
	

uninstall:
	rm $(DESTDIR)$(TARGET)
