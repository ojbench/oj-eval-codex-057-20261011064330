all:
	# Compile the solution into an executable named 'code' as required by ACMOJ
	g++ -std=c++17 -O2 -pipe -static -s -o code main.cpp

clean:
	rm -f code

