CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=alarm
SRC= alarm.c main.c
OBJDIR= build
BINDIR= bin
OBJ= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(EXEC)

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS)

alarm: $(OBJ)
	mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $^ $(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)

mrproper: clean
	rm -rf $(EXEC)
