#ifdef __unix__
   #include <GL/glut.h>
#endif

#ifdef __APPLE__
   #include "GLUT/glut.h"
#endif

#ifdef _WIN32 
   #include <gl/glut.h>
#endif

void drawWorm();
void drawBackTrack();