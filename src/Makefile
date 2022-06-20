
# to list object files
OBJS = tester.o uimain.o

#-g for debug, -03 optimization 
CFLAGS =-g -03

# first target
all: tokenizer

# target depends on all object files
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

# all object files that include header files
$(OBJS): tokenizer.h history.h

# cleans files generated in compilation
clean:
	rm -f *.o tokenizer

# run file
run:tokenizer
	./tokenizer



