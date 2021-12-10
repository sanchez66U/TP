IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS = -g -Wall -Wpedantic -Wextra -Werror -pedantic-errors -std=c11 -D_POSIX_C_SOURCE=200809L -I$(IDIR)
LDFLAGS = -lm -g -Wall -Wpedantic -Wextra -Werror -pedantic-errors -std=c11 -D_POSIX_C_SOURCE=200809L

PROG = form

_DEPS = db.h form.h lst_elm_t.h lst.h tools.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = db.o form.o lst_elm_t.o lst.o main.o tools.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#run : $(PROG)
#	./$(PROG)

all : $(PROG) # others app can be build here

$(PROG): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean mrproper

clean:
	rm -f $(ODIR)/*.o $(SDIR)/*~ core $(IDIR)/*~

delete: clean
	rm $(PROG)
