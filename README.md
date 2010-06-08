Virus-td is a tower defense game, created for an introductory AI course and a
graphics course at Cal Poly. This, specifically, is a git mirror of the
canonical Subversion repository.

Visit us on the web at http://changedmy.name/virus-td/ .

# Building and Running the Game

[freeglut], [irrKlang] and a C++ compiler are required to build the game.

[freeglut]: http://freeglut.sourceforge.net/
[irrKlang]: http://www.ambiera.com/irrklang/

## Linux

Only one of our developers is using Linux primarily, and he cba to create a
proper makefile. As a result, you will have to rebuild all the files each time
you make a change.

`make` will build an executable, and `make run` will run it.

Due to some inconsistencies with library calls and such, you may need to patch a
few things.  This is the diff that our Linux developer uses:

		diff --git a/GameSounds.h b/GameSounds.h
		index 4e7d5c2..7f6255e 100644
		--- a/GameSounds.h
		+++ b/GameSounds.h
		@@ -1,7 +1,7 @@
		 #pragma once
		 //#define VTD_SOUND
		 #ifdef VTD_SOUND
		-#include "include/irrKlang.h"
		+#include <irrKlang/irrKlang.h>
		 using namespace irrklang;
		 #endif
		 #include "MyVector.h"
		diff --git a/shadow.cpp b/shadow.cpp
		index faf6525..fb364b3 100644
		--- a/shadow.cpp
		+++ b/shadow.cpp
		@@ -218,7 +218,7 @@ void draw_shadow(int shad)
		   /* check for the polygon offset extension */
		   if (glutExtensionSupported("GL_EXT_polygon_offset")) {
			 polygonOffsetVersion = EXTENSION;
		-    glPolygonOffsetEXT(-0.1, -0.002);
		+    glPolygonOffset(-0.1, -0.002);
		   } else 
		 #endif
			 {

# Contributing using Git

Git is pretty awesome, and you can use it to contribute to this project.

## Checking out the project

	git clone git://github.com/xiongchiamiov/virus-td.git
	cd virus-td
	git svn init --prefix=svn/ svn+ssh://fileserverness.ath.cx/serv/svn/virus-td/
	git svn fetch
	git svn rebase

## Making changes

	git pull
	git svn rebase
	[hack hack hack]
	git add .
	git commit -m 'a super-helpful message'
	git svn dcommit
	git push
