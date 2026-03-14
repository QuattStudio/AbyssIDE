CC = gcc
NAME = Abyss-IDE


CFLAGS = -Iexternal/include \
         -Iexternal/include/nvg \
         -Iinclude \
         -Isrc \
         -Iinclude/internals \
         -Iinclude/core \
         -Isrc/core/window \
         -Isrc/core


DEFINES = -DGLFW_STATIC

# Source files - recurse into subfolders automatically
# SRC = $(wildcard src/*.c) $(wildcard src/**/*.c)
# SRC += external/src/nvg/*.c   # Add NanoVG source files if you have .c files

# ─────────────────────────────────────────
# Source files - recursive (works perfectly)
# ─────────────────────────────────────────
SRC := $(shell find src -name '*.c' -type f)
SRC += $(wildcard external/src/nvg/*.c)


# Libraries
LDFLAGS = -Lexternal/libs
LIBS = -lglfw3 -lopengl32 -lgdi32 -limm32 -lm

# ─────────────────────────────────────────
# Detect OS
# ─────────────────────────────────────────
ifeq ($(OS), Windows_NT)
    TARGET = $(NAME).exe
    CLEAR = cls
else
    UNAME := $(shell uname -s)
    ifeq ($(UNAME), Darwin)
        TARGET = $(NAME)
        LIBS = -lglfw -framework OpenGL -lm
    else
        TARGET = $(NAME)
        LIBS = -lglfw -lGL -lm -ldl
    endif
    CLEAR = clear
endif

# ─────────────────────────────────────────
# Build
# ─────────────────────────────────────────
all: clear $(TARGET)
	@echo ""
	@echo "Build SUCCESS ✅  →  $(TARGET)"

$(TARGET): $(SRC)
	$(CC) $(DEFINES) $(SRC) \
		$(CFLAGS) $(LDFLAGS) \
		-o $(TARGET) \
		$(LIBS)

clear:
	@$(CLEAR)

clean:
	rm -f $(NAME).exe $(NAME)

run:
	@cd game && build.bat || sh game/build.sh

.PHONY: all clean clear run






















