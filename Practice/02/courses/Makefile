outputfile: main.o teacher.o student.o course.o
	g++ main.o teacher.o student.o course.o -o outputfile

main.o: main.cpp
	g++ -c main.cpp -o main.o

teacher.o: Teacher.cpp
	g++ -c Teacher.cpp -o teacher.o

student.o: Student.cpp
	g++ -c Student.cpp -o student.o

course.o: Course.cpp
	g++ -c Course.cpp -o course.o

clean:
	rm -f *.o outputfile

run:
	./outputfile

