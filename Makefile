UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
	GLM_PATH=/home/steven/sdk
	OUT_NAME=main
endif
ifeq ($(UNAME), $(filter $(UNAME), Windows_NT MINGW64_NT-10.0))
	GLM_PATH=C:/glm-0.9.9.2
	OUT_NAME=main.exe
endif

GLM_INCLUDE_PATH=/glm

ENV_FLAGS=

CFLAGS=-g -std=c++17 -fexceptions \
-I${GLM_PATH}${GLM_INCLUDE_PATH}

LDFLAGS=

OUT=build/${OUT_NAME}
MAIN=src/*.cpp

.PHONY: build clean

build:
	make clean
	mkdir -p build
	g++ ${CFLAGS} -o ${OUT} ${MAIN} ${LDFLAGS}

image:
	make build
	./build/main > ./build/out.ppm
	eog ./build/out.ppm

clean:
	rm -rf build
