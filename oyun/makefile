all: compile run

compile:
	gcc -I ./include/ -c ./src/Taktik.c -o ./bin/Taktik.o
	gcc -I ./include/ -c ./src/ATaktik.c -o ./bin/ATaktik.o
	gcc -I ./include/ -c ./src/BTaktik.c -o ./bin/BTaktik.o
	gcc -I ./include/ -c ./src/Uretim.c -o ./bin/Uretim.o
	gcc -I ./include/ -c ./src/AUretim.c -o ./bin/AUretim.o
	gcc -I ./include/ -c ./src/BUretim.c -o ./bin/BUretim.o
	gcc -I ./include/ -c ./src/Koloni.c -o ./bin/Koloni.o
	gcc -I ./include/ -c ./src/Oyun.c -o ./bin/Oyun.o
	gcc -I ./include/ -c ./src/Test.c -o ./bin/Test.o
	gcc -I ./include/ ./src/Taktik.c ./src/ATaktik.c ./src/BTaktik.c ./src/Uretim.c ./src/AUretim.c ./src/BUretim.c ./src/Koloni.c ./src/Oyun.c ./src/Test.c -o ./bin/Test


run:
	./bin/Test
