jdk = -I /lib/jvm/java-15-openjdk/include -I /lib/jvm/java-15-openjdk/include/linux

lib = -L /lib/jvm/java-15-openjdk/lib -L /lib/jvm/java-15-openjdk/lib/server

objects = main.o 

classes = test.class

main: $(objects) $(classes)
	g++ $(jdk) $(lib) -o main $(objects) -ljvm

test.class:
	javac test.java

main.o:
	g++ $(jdk) -c main.cpp

clean:
	rm -f main *.o *.class *.log