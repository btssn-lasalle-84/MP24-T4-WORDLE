TARGET = wordle.out # Nom de l'exécutable
CXX = g++ -c # Compilateur
LD = g++ -o
CXXFLAGS = -c -Wall # Options de compilation
RM = rm *.o


all: $(TARGET) # Règle par défaut : construire l'exécutable

$(TARGET): *.o # Règle pour construire l'exécutable à partir des fichiers objets
	$(LD) $@ $^

%.o: %.cpp %.h
			$(CXX) $(CFLAGS) $^

clean: # Cible clean : supprimer les fichiers objets
	$(RM)

cleanall: # Cible cleanall : supprimer les fichiers objets et l'exécutable
	$(RM) $(TARGET)