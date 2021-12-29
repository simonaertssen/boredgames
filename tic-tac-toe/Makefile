# The sources we're building
SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)

# What we're building
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
PRODUCT = main
TESTS = tests
TESTHEADERS = $(wildcard tests/*.h)

# What we're building with
CC = gcc -Wno-deprecated-declarations -Wno-unused-function # Added this because of legacy timers
CFLAGS = -std=c99 -Wall -m64
LDFLAGS = -flto #-fuse-ld=gold This is unknown on my laptop

# We need to link against the timing library for whatever OS we're on.
PLATFORM = $(shell uname)
ifeq ($(PLATFORM),Linux)
	LDFLAGS += -lrt
else ifeq ($(PLATFORM),Darwin)
	LDFLAGS += -arch x86_64 -framework CoreServices
endif

# Determine which profile --debug or release-- we should build against, and set
# CFLAGS appropriately.
OLD_MODE = $(shell cat .buildmode 2> /dev/null)
ifeq ($(DEBUG),1)
# We want debug mode.
CFLAGS += -O0 -g
ifneq ($(OLD_MODE),debug)
$(shell echo debug >.buildmode)
endif
else
# We want release mode.
CFLAGS += -O3 -DNDEBUG
ifneq ($(OLD_MODE),release)
$(shell echo release >.buildmode)
endif
endif

# By default, make the product.
all:		$(PRODUCT)

# How to compile a C file
%.o:		%.c $(HEADERS) .buildmode
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -o $@ -c $<

# How to link the product
$(PRODUCT):	$(OBJECTS) .buildmode
	$(CC) $(OBJECTS) $(LDFLAGS) $(EXTRA_LDFLAGS) -o $@

# How to clean up
clean:
	$(RM) game *.o .buildmode *.gcov *.gcno *.gcda *.out.*

# Make unit tests
test: 
	$(CC) $(TESTHEADERS) 