TARGET = wordle.out # Nom de l'exécutable
OBJETS = Dictionnaire.o  Joueur.o  main.o  Partie.o  Wordle.o
CXX = g++ -c # Compilateur
LD = g++ -o
CXXFLAGS = -c -Wall # Options de compilation
RM = rm -f

all: $(TARGET) # Règle par défaut : construire l'exécutable

$(TARGET): $(OBJETS) # Règle pour construire l'exécutable à partir des fichiers objets
	$(LD) $@ $^

main.o: main.cpp
	$(CXX) $(CFLAGS) $<

%.o: %.cpp %.h
	$(CXX) $(CFLAGS) $<

clean: # Cible clean : supprimer les fichiers objets
	$(RM) *.o *.gch *.*~

cleanall: # Cible cleanall : supprimer les fichiers objets et l'exécutable
	$(RM) *.o *.gch *.*~ $(TARGET)
