jdk = -I /lib/jvm/java-15-openjdk/include -I /lib/jvm/java-15-openjdk/include/linux

lib = -L /lib/jvm/java-15-openjdk/lib -L /lib/jvm/java-15-openjdk/lib/server

objects = main.o hasher.o

classes = hasher.class

main: $(objects) $(classes)
	g++ $(jdk) $(lib) -o main $(objects) -ljvm

hasher.class:
	javac hasher.java

main.o:
	g++ $(jdk) -c main.cpp

hasher.o:
	g++ $(jdk) -c hasher.cpp

clean:
	rm -f main *.o *.class *.log