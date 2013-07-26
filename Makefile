all:
	gcc hello.c -o bin/hello
	gcc math.c -lm -o bin/math
	gcc enum.c -o bin/enum
