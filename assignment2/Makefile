build:
	gcc variables.c -o variables.out || true
	gcc relations.c -o relations.out || true
	gcc factorial.c -o factorial.out || true
	gcc temperature.c -o temperature.out || true
	gcc quadratic.c -o quadratic.out -lm || true
	gcc upper.c -o upper.out || true
	gcc binary.c -o binary.out || true

run: build
	./variables.out
	./relations.out
	./factorial.out
	./temperature.out
	./quadratic.out
	./upper.out
	./binary.out
