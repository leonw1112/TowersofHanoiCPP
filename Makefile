CC = g++
CFLAGS = -Wall -g

OBJ = main.o game.o slices.o



main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -MD -MP $< -c -o $@

clean:
	rm *.o ./main *.d
