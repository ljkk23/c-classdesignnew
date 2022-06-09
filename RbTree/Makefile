test: start main.o testcpp.o
	g++ ./tmp/*.o -o ./output/test
	g++ ./testCpp/*.o -o ./testCpp/write

start:
	mkdir -p tmp

main.o:
	g++ -Wall -c ./src/testmain.cpp -I ./include   -o ./tmp/testmain.o

testcpp.o:
	g++ -Wall -c ./testCpp/write.cpp -I ./include   -o ./testCpp/write.o

clean:
	rm -rf ./tmp

run:test
	./output/test