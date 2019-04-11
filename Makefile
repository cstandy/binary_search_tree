CC:=g++
exe:=run.out
obj:=main.o binary_search_tree.o

all: $(obj)
	$(CC) -o $(exe) $(obj)
%.o: %.c
	$(CC) -c $^ -o $@
clean:
	rm $(obj) $(exe)
