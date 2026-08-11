CC = gcc

CFLAGS = -I include

OBJ = obj/main.o \
      obj/addition.o \
      obj/subtraction.o \
      obj/multiplication.o \
      obj/division.o \
      obj/compare.o \
      obj/create_list.o \
      obj/delete_list.o \
      obj/insert_first.o \
      obj/insert_last.o \
      obj/print_list.o \
      obj/utils.o

TARGET = bin/apc


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


obj/%.o: source/%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f obj/*.o
	rm -f bin/apc