all: listaCentros.o listaUtentes.o listaVacinas.o utente.o centroVacinacao.o vacina.o main.c
	gcc -g -o main.exe utente.o  listaCentros.o centroVacinacao.o listaUtentes.o listaVacinas.o vacina.o main.c

listaCentros.o: centroVacinacao.o ./02-Functions/listaCentros.c
	gcc -g -o listaCentros.o centroVacinacao.o ./02-Functions/listaCentros.c -c 

listaVacinas.o: vacina.o ./02-Functions/listaVacinas.c
	gcc -g -o listaVacinas.o vacina.o ./02-Functions/listaVacinas.c -c

centroVacinacao.o: ./02-Functions/centroVacinacao.c
	gcc -g -o centroVacinacao.o ./02-Functions/centroVacinacao.c -c

listaUtentes.o: utente.o vacina.o ./02-Functions/listaUtentes.c
	gcc -g -o listaUtentes.o utente.o vacina.o ./02-Functions/listaUtentes.c -c

utente.o: utente.o vacina.o ./02-Functions/utente.c
	gcc -g -o utente.o vacina.o ./02-Functions/utente.c -c
vacina.o: ./02-Functions/vacina.c
	gcc -g -o vacina.o ./02-Functions/vacina.c -c

clean: 
	del vacina.o utente.o centroVacinacao.o listaVacinas.o listaCentros.o listaUtentes.o main.exe

run:
	mingw32-make all
	./main.exe