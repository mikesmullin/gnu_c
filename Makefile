ooc:
	gcc -o bin/ooc3 ooc3/class.c ooc3/Array.c ooc3/main.c
all:
	gcc hello.c -o bin/hello
	gcc math.c -lm -o bin/math
	gcc enum.c -o bin/enum
	gcc ooc1/ooc.c ooc1/Set.c -o bin/ooc
	gcc ooc2/Class.c -o bin/Class
