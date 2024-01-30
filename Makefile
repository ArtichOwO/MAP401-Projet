#############################################################################
# Fichier Makefile
# UE MAP401 - DLST - UGA - 2023/2024
#############################################################################

#############################################################################
# définition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'accès aux sources
SRCDIR = src

# chemin d'accès aux librairies (interfaces)
INCDIR = include

# chemin d'accès aux librairies (binaires)
LIBDIR = .

# options pour l'édition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des exécutables
EXECUTABLES = test_image test_geom2d


#############################################################################
# définition des règles
#############################################################################

########################################################
# la règle par défaut
all: $(EXECUTABLES)

########################################################
# règles génériques
%.o: $(SRCDIR)/%.c
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $(SRCDIR)/$@

%: %.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $(addprefix $(SRCDIR)/, $^) $(LDOPTS) -o $@

########################################################
# règles explicites de compilation séparée de modules
# n'ayant pas de fichier .h ET/OU dépendant d'autres modules
image.o: $(SRCDIR)/image.c $(INCDIR)/image.h $(INCDIR)/types_macros.h

geom2d.o: $(SRCDIR)/geom2d.c $(INCDIR)/geom2d.h $(INCDIR)/types_macros.h

contour.o: $(SRCDIR)/contour.c $(INCDIR)/contour.h

test_image.o: $(SRCDIR)/test_image.c $(INCDIR)/image.h

test_geom2d.o: $(SRCDIR)/test_geom2d.c $(INCDIR)/geom2d.h

########################################################
# règles explicites de création des exécutables

test_image: test_image.o image.o

test_geom2d: test_geom2d.o geom2d.o

# règle pour "nettoyer" le répertoire
clean:
	rm -fR $(EXECUTABLES) $(SRCDIR)/*.o
