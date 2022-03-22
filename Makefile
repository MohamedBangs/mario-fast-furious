CC=g++
#OBJSGraphique=obj/Camera.o\ obj/Joueur.o\ obj/mainExemple.o\ obj/mainTest.o
CFLAGS=-Wall -c 

################################################################################ -Werror -Wextra

all: bin/courseGraphique bin/courseTexte

bin/courseGraphique: obj/Camera.o obj/Joueur.o obj/Collision.o obj/SdlJeuxUtil.o obj/MenuSdl.o obj/Terrain.o obj/AfficheJeuxSdl.o obj/AfficheScore.o obj/SdlJeux.o obj/SdlMain.o
	g++ obj/Camera.o obj/Joueur.o obj/SdlJeuxUtil.o obj/Collision.o obj/MenuSdl.o obj/Terrain.o obj/AfficheJeuxSdl.o obj/AfficheScore.o obj/SdlJeux.o obj/SdlMain.o -o bin/courseGraphique -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

bin/courseTexte: obj/MenuText.o obj/Joueur.o obj/TextJeux.o obj/TextMain.o obj/WinText.o obj/Terrain.o obj/AfficheJeux.o
	g++ obj/MenuText.o obj/Joueur.o obj/TextJeux.o obj/TextMain.o obj/WinText.o obj/Terrain.o obj/AfficheJeux.o -o bin/courseTexte -lncurses

###################################GRAPHIQUE#############################################

obj/Camera.o: src/JeuxCore/Camera.h src/JeuxCore/Camera.cpp src/JeuxCore/Joueur.h src/JeuxCore/Joueur.cpp
	$(CC) $(CFLAGS) src/JeuxCore/Camera.cpp -o obj/Camera.o

obj/Joueur.o: src/JeuxCore/Joueur.h src/JeuxCore/Joueur.cpp
	$(CC) $(CFLAGS) src/JeuxCore/Joueur.cpp -o obj/Joueur.o

obj/Terrain.o: src/JeuxCore/Terrain.h src/JeuxCore/Terrain.cpp
	$(CC) $(CFLAGS) src/JeuxCore/Terrain.cpp -o obj/Terrain.o

obj/Collision.o: src/JeuxCore/Collision.h src/JeuxCore/Collision.cpp
	$(CC) $(CFLAGS) src/JeuxCore/Collision.cpp -o obj/Collision.o

obj/SdlJeuxUtil.o: src/JeuxSdl2/SdlJeuxUtil.h src/JeuxSdl2/SdlJeuxUtil.cpp
	$(CC) $(CFLAGS) src/JeuxSdl2/SdlJeuxUtil.cpp -o obj/SdlJeuxUtil.o

obj/MenuSdl.o: src/JeuxSdl2/MenuSdl.h src/JeuxSdl2/MenuSdl.cpp
	$(CC) $(CFLAGS) src/JeuxSdl2/MenuSdl.cpp -o obj/MenuSdl.o

obj/AfficheScore.o: src/JeuxSdl2/AfficheScore.h src/JeuxSdl2/AfficheScore.cpp
	$(CC) $(CFLAGS) src/JeuxSdl2/AfficheScore.cpp -o obj/AfficheScore.o

obj/AfficheJeuxSdl.o: src/JeuxSdl2/AfficheJeuxSdl.h src/JeuxSdl2/AfficheJeuxSdl.cpp src/JeuxCore/Camera.h src/JeuxCore/Camera.cpp src/JeuxCore/Joueur.h src/JeuxCore/Joueur.cpp src/JeuxCore/Collision.h src/JeuxCore/Collision.cpp src/JeuxSdl2/SdlJeuxUtil.h src/JeuxSdl2/SdlJeuxUtil.cpp
	$(CC) $(CFLAGS) src/JeuxSdl2/AfficheJeuxSdl.cpp -o obj/AfficheJeuxSdl.o

obj/SdlJeux.o: src/JeuxCore/Joueur.h src/JeuxCore/Joueur.cpp src/JeuxSdl2/SdlJeuxUtil.h src/JeuxSdl2/SdlJeuxUtil.cpp src/JeuxSdl2/MenuSdl.h src/JeuxSdl2/MenuSdl.cpp src/JeuxCore/Terrain.h src/JeuxCore/Terrain.cpp src/JeuxSdl2/AfficheJeuxSdl.h src/JeuxSdl2/AfficheJeuxSdl.cpp src/JeuxSdl2/AfficheScore.h src/JeuxSdl2/AfficheScore.cpp src/JeuxSdl2/SdlJeux.h src/JeuxSdl2/SdlJeux.cpp
	$(CC) $(CFLAGS) src/JeuxSdl2/SdlJeux.cpp -o obj/SdlJeux.o

obj/SdlMain.o: src/JeuxSdl2/SdlJeux.h src/JeuxSdl2/SdlJeux.cpp src/JeuxSdl2/SdlMain.cpp
	$(CC) $(CFLAGS) src/JeuxSdl2/SdlMain.cpp -o obj/SdlMain.o

########################################TEXTUELLE######################################################

obj/WinText.o: src/JeuxText/WinText.h src/JeuxText/WinText.cpp
	$(CC) $(CFLAGS) src/JeuxText/WinText.cpp -o obj/WinText.o -lncurses

obj/MenuText.o: src/JeuxText/MenuText.h src/JeuxText/MenuText.cpp src/JeuxText/WinText.h src/JeuxText/WinText.cpp
	$(CC) $(CFLAGS) src/JeuxText/MenuText.cpp -o obj/MenuText.o

obj/AfficheJeux.o: src/JeuxText/AfficheJeux.h src/JeuxText/AfficheJeux.cpp src/JeuxCore/Joueur.h src/JeuxCore/Joueur.cpp
	$(CC) $(CFLAGS) src/JeuxText/AfficheJeux.cpp -o obj/AfficheJeux.o

obj/TextJeux.o: src/JeuxText/MenuText.h src/JeuxText/MenuText.cpp src/JeuxText/TextJeux.h src/JeuxText/TextJeux.cpp src/JeuxText/WinText.h src/JeuxText/WinText.cpp src/JeuxCore/Terrain.h src/JeuxCore/Terrain.cpp src/JeuxText/AfficheJeux.h src/JeuxText/AfficheJeux.cpp
	$(CC) $(CFLAGS) src/JeuxText/TextJeux.cpp -o obj/TextJeux.o

obj/TextMain.o: src/JeuxText/TextJeux.h src/JeuxText/TextJeux.cpp src/JeuxText/TextMain.cpp
	$(CC) $(CFLAGS) src/JeuxText/TextMain.cpp -o obj/TextMain.o

########################################################################################################
clean:
	rm -rf obj/* bin/*
