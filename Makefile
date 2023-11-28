GPP_FLAGS = -std=c++11 -lglfw -lGL -ldl -L $(FILES_TO_BUILD_INCLUDE)

PROJECT_NAME = VATTUENGINE

FILES_TO_BUILD_SRC := $(wildcard src/*.cpp)
FILES_TO_BUILD_GLAD := $(wildcard glad/*.c)
FILES_TO_BUILD_INCLUDE := $(wildcard include/*.hpp)

run:
	./$(PROJECT_NAME)

build:
	g++ $(FILES_TO_BUILD_SRC) $(FILES_TO_BUILD_GLAD) -o $(PROJECT_NAME) $(GPP_FLAGS)
	chmod +x $(PROJECT_NAME)

all:
	make build
	echo -----------------
	make run