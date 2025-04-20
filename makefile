# Le programme est constitué des fichiers suivants: main.cpp, class.cpp, class.h et io.cpp
# Le makefile permet d'automatiser la compilation


# all regroupe tous les exécutables 
all: etoilesbinaires

# ce sont les fichiers #include 
class.o: class.cpp class.h
main.o: main.cpp class.h io.cpp
io.o: io.cpp class.cpp

etoilesbinaires: class.o main.o io.o
				g++ class.o main.o io.o -o etoilesbinaires
# pour nettoyer les fichiers temporaires
clean:
				rm -f *~ *.o \#*
# pour tout nettoyer
cleanall: clean	
				rm -f etoilesbinaires