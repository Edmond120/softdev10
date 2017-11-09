all: batsignal.c
	gcc -o batsignal batsignal.c
run: all
	./batsignal
clean:
	rm batsignal
