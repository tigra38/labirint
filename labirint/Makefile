SRC = main.cpp
TARGET = labirint
LIBLABIRINT = labirint
PREFIX = /usr/local/bin

labirint:	$(SRC) liblabirint
	g++ -o $(TARGET) $(SRC) -L. -llabirint -std=c++17

liblabirint:	$(LIBLABIRINT).cpp $(LIBLABIRINT).h
	g++ -o $(LIBLABIRINT).o $(LIBLABIRINT).cpp -c
	ar rc lib$(LIBLABIRINT).a $(LIBLABIRINT).o

clean:
	rm *.o *.a

install:
	install $(TARGET) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)
