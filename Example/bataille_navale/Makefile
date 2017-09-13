# Release/Debug
DEBUG=yes

# Directories
SRC_DIR = SRC
INC_DIR = INC
OBJ_DIR = OBJ
BIN_DIR = BIN

CC = gcc
CFLAGS = -W -Wall -Wextra -O2 -lm
BIN = TestLib

ifeq ($(DEBUG), yes) 
	CFLAGS += -g -DDEBUG
endif

SRC = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ = $(addsuffix .o, $(basename $(subst ${SRC_DIR}, ${OBJ_DIR}, ${SRC})))


.PHONY: clear dir
.SUFFIXES:

all: dir $(BIN_DIR)/$(BIN)

#
# BIN creation.
#

$(BIN_DIR)/$(BIN): $(OBJ)
ifeq ($(DEBUG), yes)
	$(CC) $(OBJ) -o $@ -I $(INC_DIR) $(CFLAGS)
else 
	@$(CC) $(OBJ) -o $@ -I $(INC_DIR) $(CFLAGS)

endif
	@echo "$(BIN) well created !"

#
# Object files creation.
#

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
ifeq ($(DEBUG), yes) 
	$(CC) -c $^ -o $@ -I $(INC_DIR) $(CFLAGS)
else 
	@$(CC) -c $^ -o $@ -I $(INC_DIR) $(CFLAGS)
	@echo -e "Creating $@"
endif


#
# Other usefull targets.
#

clean:
ifeq ($(DEBUG), yes) 
	rm -rf ./$(OBJ_DIR);
	rm -rf ./$(BIN_DIR);
else
	@rm -rf ./$(OBJ_DIR);
	@echo -e "Remove object file and directory"
	@rm -rf ./$(BIN_DIR);
	@echo -e "Remove executable and remove bin directory"
endif


rebuild: clean all

#
# Screen cleaning.
#

clear:
	clear
#
# Repository creation.
#

dir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

