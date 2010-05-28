default: virus-td
virus-td: clean
	g++ -g -o virus-td -lGL -lGLU -lglut *.cpp

clean:
	touch virus-td && rm virus-td

run:
	./virus-td
