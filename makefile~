#MAKEFILE for clonie

CC=gcc
CLFAGS=
LDFLAGS=
SOURCES=src/*
EXECUTABLE=bin/clonie
EXECUTABLEDIR=bin/*	
BIN=/usr/local/bin/clonie

all: clonie

clonie:
	@echo Removing old files...
	@rm -rf bin
	@echo Making clonie...
	@mkdir bin
	@$(CC) $(SOURCES) -o $(EXECUTABLE)
	@echo Clonie has been made. Before executing, make sure to read the README for important information, including dependencies.

install: install-clonie

install-clonie:
	@echo Removing old files...
	@rm -rf $(BIN)
	@echo Creating directories...
	@mkdir $(BIN)
	@echo Copying new files...
	@cp -R $(EXECUTABLEDIR) $(BIN)/
	@echo Clonie has been installed. Before executing, make sure to read the README for important information, including dependencies.
