# edit this makefile so that running make compiles your enigma program
#all: enigma
#
#enigma: Main.o Rotor.o Reflector.o Plugboard.o
#	g++ -o enigma Main.o Rotor.o Reflector.o Plugboard.o
#
#Main.o: Main.cpp
#	g++ -c Main.cpp -o Main.o
#
#clean:
#	rm -rf enigma *.o
#
#.PHONY: clean

#
#
#
#
#
#ld -N Main.o Rotor.o Reflector.o Plugboard.o -o enigma

#all: enigma
#
#enigma: Main.cpp Main.o Rotor.cpp Rotor.o Reflector.cpp Reflector.o Plugboard.cpp Plugboard.o Mapper.cpp Mapper.o
#	ld -N Main.o Mapper.o Rotor.o Reflector.o Plugboard.o -o enigma
#
#Main.o: Main.cpp Rotor.cpp Reflector.cpp Plugboard.cpp Mapper.cpp
#	g++ -c Main.cpp Mapper.cpp Rotor.cpp Reflector.cpp Plugboard.cpp -o Main.o
#
#Mapper.o: Mapper.cpp
#	g++ -c Mapper.cpp -o Mapper.o
#
#Rotor.o: Rotor.cpp Mapper.cpp
#	g++ -c Rotor.cpp Mapper.cpp -o Rotor.o
#
#Reflector.o: Reflector.cpp Mapper.cpp
#	g++ -c Reflector.cpp Mapper.cpp -o Reflector.o
#
#Plugboard.o: Plugboard.cpp Mapper.cpp
#	g++ -c Plugboard.cpp Mapper.cpp -o Plugboard.o
#
#clean:
#	rm -rf *.o
#
#.PHONY: all
#
#.PHONE: clean

#all: enigma
#
#enigma: Main.cpp Main.o Rotor.cpp Rotor.o Reflector.cpp Reflector.o Plugboard.cpp Plugboard.o Mapper.cpp Mapper.o
#	ld -N Main.o Mapper.o Rotor.o Reflector.o Plugboard.o -o enigma
#
#Main.o: Main.cpp Rotor.cpp Reflector.cpp Plugboard.cpp Mapper.cpp
#	g++ -c Main.cpp -o Main.o
#
#Mapper.o: Mapper.cpp
#	g++ -c Mapper.cpp -o Mapper.o
#
#Rotor.o: Rotor.cpp Mapper.cpp
#	g++ -c Rotor.cpp -o Rotor.o
#
#Reflector.o: Reflector.cpp Mapper.cpp
#	g++ -c Reflector.cpp -o Reflector.o
#
#Plugboard.o: Plugboard.cpp Mapper.cpp
#	g++ -c Plugboard.cpp -o Plugboard.o
#
#clean:
#	rm -rf *.o
#
#.PHONY: all
#
#.PHONE: clean	

CC = g++
CFLAGS = -Wall -Werror -pedantic -g

enigma: Main.o Mapper.o Rotor.o Reflector.o Plugboard.o

Main.o: Mapper.hpp Rotor.hpp Reflector.hpp Plugboard.hpp

Mapper.o: Mapper.hpp

Rotor.o: Mapper.hpp Rotor.hpp

Reflector.o: Mapper.hpp Reflector.hpp

Plugboard.o: Mapper.hpp Plugboard.hpp

clean:
	$(RM) enigma *.o *~

.PHONY: clean