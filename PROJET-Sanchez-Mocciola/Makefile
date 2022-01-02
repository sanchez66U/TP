# project name (generate executable with this name)
TARGET = projet

CC = gcc

# change these to proper directories where each file should be
SRCDIR = src
OBJDIR = obj
INCLDIR = include

# compiling flags here
#CFLAGS = -std=c99 -Wall -I$(INCLDIR)
CFLAGS = -g -Wall -Wextra -std=c11 -I$(INCLDIR)

# linking flags here
LFLAGS = -Wall -I$(INCLDIR) -lm

SOURCES  = $(wildcard $(SRCDIR)/*.c)
INCLUDES = $(wildcard $(INCLDIR)/*.h)

OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))


.PHONY: run clean delete

all : $(TARGET)
$(TARGET) :$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -lm
	
$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

clean: $(OBJECTS)
	rm -rf $(OBJDIR)/$(OBJECTS)

delete: $(BINDIR)/$(TARGET)
	rm -rf $(BINDIR)/$(TARGET)


