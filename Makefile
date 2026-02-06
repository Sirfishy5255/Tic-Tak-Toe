.PHONY: build run clean rebuild

build:
	@cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
	@cmake --build build

run: build
	@./build/tictactoe

clean:
	@rm -rf build

rebuild: clean build
