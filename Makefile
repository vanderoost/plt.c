CFLAGS = -Wall -Wextra

NAME = main
BIN = bin
OBJ = obj
SRC = src

EXEC = $(BIN)/$(NAME)

BIN_SRCS = $(wildcard $(SRC)/*.c)
LIB_SRCS = $(wildcard $(SRC)/*/*.c)
ALL_SRCS = $(BIN_SRCS) $(LIB_SRCS)

BINS = $(patsubst $(SRC)/%.c,$(BIN)/%,$(BIN_SRCS))
OBJS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(LIB_SRCS))
DEPS = $(patsubst $(SRC)/%.c,$(OBJ)/%.d,$(ALL_SRCS))

all: $(BINS)

$(BINS): $(BIN)/%: $(OBJ)/%.o $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

run: $(EXEC)
	$<

watch:
	@find $(SRC) -type f | entr -c make run

clean:
	$(RM) -r $(BIN) $(OBJ)

-include $(DEPS)

.PHONY: all run watch clean
