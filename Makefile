CC = g++
exec_file = game
debug_file = debug
$(exec_file): location.o driver.o cave.o pokestop.o pokemon.o player.o rock.o flying.o psychic.o
	$(CC) location.o driver.o cave.o pokestop.o pokemon.o player.o rock.o flying.o psychic.o -o $(exec_file)
debug: location.cpp driver.cpp cave.cpp pokestop.cpp pokemon.cpp player.cpp rock.cpp flying.cpp psychic.cpp
	$(CC) location.cpp driver.cpp cave.cpp pokestop.cpp pokemon.cpp player.cpp rock.cpp flying.cpp psychic.cpp -D DEBUG -o $(debug_file)
location.o: location.cpp
	$(CC) -c location.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
cave.o: cave.cpp
	$(CC) -c cave.cpp
pokestop.o: pokestop.cpp
	$(CC) -c pokestop.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
player.o: player.cpp
	$(CC) -c player.cpp
rock.o: rock.cpp
	$(CC) -c rock.cpp
flying.o: flying.o
	$(CC) -c flying.cpp
psychic.o: psychic.o
	$(CC) -c psychic.cpp
clean:
	rm -f *.o *.out *.gch $(exec_file) $(debug_file)
open_all_vim:
	vim -p *.cpp *.h
