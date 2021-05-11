CC = gcc
FLAG = -g -O2 -Wall

math = decimal expcc angle prob run texpcc

all : $(math)
	@-termux-elf-cleaner $^ 2> /dev/null

cJSON:cJSON.c
	$(CC) -c -o $@ $^ $(FLAG) -std=c89 -fstack-protector-all -fPIC -pedantic -Werror -Wstrict-prototypes -Wwrite-strings -Wshadow -Winit-self -Wcast-align -Wformat=2 -Wmissing-prototypes -Wstrict-overflow=2 -Wcast-qual -Wc++-compat -Wundef -Wswitch-default -Wconversion

str:str.c
	$(CC) -c -o $@ $^ $(FLAG)
	$(CC) -o $@ $^ $(FLAG) -DMAIN

decimal:decimal.c
	$(CC) -c $^ $(FLAG)
	$(CC) -o $@ $^ $(FLAG) -lm -DMAIN

termux_api:termux_api.c
	$(CC) -c -o $@ $^ $(FLAG)

expcc:expcc.c decimal.o str.o termux_api.o
	$(CC) -c -o $@ expcc.c $(FLAG)
	$(CC) -o $@ $^ $(FLAG) -lm -DMAIN

texpcc:texpcc.c expcc.o decimal.o str.o termux_api.o cJSON.o
	$(CC) -o $@ $^ $(FLAG) -lm -fstack-protector-all
#-DDEBUG

angle:angle.c decimal.o
	$(CC) -o $@ $^ $(FLAG) -lm -DMAIN

prob:prob.c
	$(CC) -o $@ $^ $(FLAG) -lm -DMAIN

run:run.c
	$(CC) -o $@ $^ $(FLAG)

t:
	rm -rf math.tgz
	tar -czf math.tgz *.c *.h makefile

s:
	scp -P8022 makefile *.c *.h 192.168.43.1:~/math/

clean:
	rm -rf $(math) *.o *.exe *.out
