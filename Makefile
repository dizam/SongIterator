songs.out : main.o song.o  
	g++ -ansi -Wall -g -o songs.out main.o song.o  

main.o : main.cpp song.h 
	g++ -ansi -Wall -g -c main.cpp

song.o : song.cpp song.h 
	g++ -ansi -Wall -g -c song.cpp

clean : 
	rm -f songs.out main.o  song.o   
