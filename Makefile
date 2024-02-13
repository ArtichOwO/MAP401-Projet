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
EXECUTABLES = test_image test_geom2d test_contour


#############################################################################
# définition des règles
#############################################################################

########################################################
# la règle par défaut
all: $(EXECUTABLES)

########################################################
# règles génériques
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

%: %.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $(addprefix $(SRCDIR)/, $^) $(LDOPTS) -o $@

########################################################
# règles explicites de compilation séparée de modules
# n'ayant pas de fichier .h ET/OU dépendant d'autres modules
$(SRCDIR)/image.o: $(SRCDIR)/image.c $(INCDIR)/image.h $(INCDIR)/types_macros.h

$(SRCDIR)/geom2d.o: $(SRCDIR)/geom2d.c $(INCDIR)/geom2d.h $(INCDIR)/types_macros.h

$(SRCDIR)/contour.o: $(SRCDIR)/contour.c $(INCDIR)/contour.h

$(SRCDIR)/test_image.o: $(SRCDIR)/test_image.c $(INCDIR)/image.h

$(SRCDIR)/test_geom2d.o: $(SRCDIR)/test_geom2d.c $(INCDIR)/geom2d.h

$(SRCDIR)/test_contour.o: $(SRCDIR)/test_contour.c $(INCDIR)/image.h $(INCDIR)/contour.h

$(SRCDIR)/liste.o: $(SRCDIR)/liste.c $(INCDIR)/liste.h $(INCDIR)/geom2d.h

########################################################
# règles explicites de création des exécutables

test_image: $(SRCDIR)/test_image.o $(SRCDIR)/image.o

test_geom2d: $(SRCDIR)/test_geom2d.o $(SRCDIR)/geom2d.o

test_contour: $(SRCDIR)/test_contour.o $(SRCDIR)/image.o \
	$(SRCDIR)/geom2d.o $(SRCDIR)/contour.o

# règle pour "nettoyer" le répertoire
clean:
	rm -fR $(EXECUTABLES) $(SRCDIR)/*.o
