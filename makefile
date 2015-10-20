CC = g++
CFLAGS = -g -Wall -Werror -pedantic

enigma: Main.o Rotor.o Reflector.o Plugboard.o Mapper.o
	$(CC) $(CFLAGS) $^ -o enigma

Main.o: Main.cpp Plugboard.hpp Reflector.hpp Rotor.hpp
	$(CC) $(CFLAGS) -c $<

Rotor.o: Rotor.cpp Rotor.hpp Mapper.hpp
	$(CC) $(CFLAGS) -c $<

Reflector.o: Reflector.cpp Reflector.hpp Mapper.hpp
	$(CC) $(CFLAGS) -c $<

Plugboard.o: Plugboard.cpp Plugboard.hpp Mapper.hpp
	$(CC) $(CFLAGS) -c $<

Mapper.o: Mapper.cpp Mapper.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf enigma *.o

.PHONY: clean