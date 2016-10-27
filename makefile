rand: randev.c
	gcc randev.c
run:
	./a.out
clean:
	rm rand.txt
	rm *~
	rm a.out