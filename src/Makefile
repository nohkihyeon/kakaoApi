CC = gcc
TARGET = keywordSearch_exe 
INC = -I/home/khnoh/json/kakaoApi/include
LFLAGS = -ljansson
CFLAGS = -W -Wall $(INC)
CFILES = search_keyword.c 	\
		 get_addressInfo.c  \
		 writeJson.c		\
		 data_parsing.c 	\

OBJECT = $(CFILES:.c=.o)

all : $(TARGET)

.c.o:
	$(CC) -c  $(CFLAGS) $*.c  

$(TARGET) : $(OBJECT)
	$(CC) $(OBJECT) $(CFLAGS) $(LFLAGS) -o $(TARGET) 

clean :
	rm *.o keywordSearch_exe
