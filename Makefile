#############################################################################
# Fichier Makefile
# UE MAP401 - DLST - UGA - 2023/2024
#############################################################################

#############################################################################
# d�finition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acc�s aux sources
SRCDIR = src

# chemin d'acc�s aux librairies (interfaces)
INCDIR = include

# chemin d'acc�s aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des ex�cutables
EXECUTABLES = test_image test_geom2d test_contour


#############################################################################
# d�finition des r�gles
#############################################################################

########################################################
# la r�gle par d�faut
all: $(EXECUTABLES)

########################################################
# r�gles g�n�riques
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
# r�gles explicites de compilation s�par�e de modules
# n'ayant pas de fichier .h ET/OU d�pendant d'autres modules
image.o: $(SRCDIR)/image.c $(INCDIR)/image.h $(INCDIR)/types_macros.h

geom2d.o: $(SRCDIR)/geom2d.c $(INCDIR)/geom2d.h $(INCDIR)/types_macros.h

contour.o: $(SRCDIR)/contour.c $(INCDIR)/contour.h

test_image.o: $(SRCDIR)/test_image.c $(INCDIR)/image.h

test_geom2d.o: $(SRCDIR)/test_geom2d.c $(INCDIR)/geom2d.h

test_contour.o: $(SRCDIR)/test_contour.c $(INCDIR)/image.h $(INCDIR)/contour.h
liste.o: $(SRCDIR)/liste.c $(INCDIR)/liste.h $(INCDIR)/geom2d.h

########################################################
# r�gles explicites de cr�ation des ex�cutables

test_image: test_image.o image.o

test_geom2d: test_geom2d.o geom2d.o

test_contour: test_contour.o image.o geom2d.o contour.o

# r�gle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) $(SRCDIR)/*.o
