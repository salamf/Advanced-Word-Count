CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
LIBS = -lm 

all: clean word_count test 

clean:
	@echo Removing previously compiled code 
	rm -rf word_count *.o *.out *.out.dSYM

word_count: 
	gcc $(CFLAGS) src/word_count.c $(LIBS) -o word_count

debug: 
	gcc $(CFLAGS) -D DEBUG src/word_count.c  $(LIBS) -o debug.out 

test: clean tests.out
	@./tests.out

tests.out: test/test_main.c 
	@echo Compiling $@
	gcc $(CFLAGS) -D TEST test/vendor/unity.c test/test_main.c $(LIBS) -o tests.out 

