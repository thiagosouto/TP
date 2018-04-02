CFLAGS=-lm -Wall

SAIDA=saidaTP1.txt


CC:=gcc
EXEC:=TP
RM:=rm -rf

HRD:=$(wildcard *.h)
SRC:=$(wildcard *.c)
OBJ:=$(SRC:.c=.o)


#--------------------/------------------------

all:$(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

$(OBJ):$(SRC) $(HRD)
	$(CC) $(SRC) -c $(CFLAGS)

dbug:
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS) -g


.PHONY:clean

clean:
	$(RM) $(OBJ) $(EXEC) $(SAIDA)
