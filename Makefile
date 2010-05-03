default: virus-td
virus-td: clean
	g++ -o virus-td -lGL -lGLU -lglut *.cpp

clean:
	rm virus-td
