CC = g++
exec_file = game
$(exec_file): location.o driver.o cave.o pokestop.o
	$(CC) location.o driver.o cave.o pokestop.o -o $(exec_file)
location.o: location.cpp
	$(CC) -c location.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
cave.o: cave.cpp
	$(CC) -c cave.cpp
pokestop.o: pokestop.cpp
	$(CC) -c pokestop.cpp
clean:
	rm -f *.o *.out *.gch $(exec_file)
