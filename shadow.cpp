
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>      
#include <GL/glut.h> 
#include "models.h"
#include "shadow.h"



#ifndef M_PI
#define M_PI 3.14159265
#endif

/* Variable controlling various rendering modes. */
static int stencilReflection = 1, stencilShadow = 1, offsetShadow = 1;
static int renderShadow = 1, renderDinosaur = 1, renderReflection = 1;
static int linearFiltering = 0, useMipmaps = 0, useTexture = 1;
static int reportSpeed = 0;
static int animation = 1;
static GLboolean lightSwitch = GL_TRUE;
static int directionalLight = 1;
static int forceExtension = 0;

/* Time varying or user-controled variables. */
static float jump = 0.0;
static float lightAngle = 0.0, lightHeight = 20;
GLfloat angle = -150;   /* in degrees */
GLfloat angle2 = 30;   /* in degrees */

int moving, startx, starty;
int lightMoving = 0, lightStartX, lightStartY;

enum {
  MISSING, EXTENSION, ONE_DOT_ONE
};
int polygonOffsetVersion;

static GLdouble bodyWidth = 3.0;
/* *INDENT-OFF* */
static GLfloat light_Position[4] = {1.5, 1.0, 1.5, 1.0};
//static GLfloat lightPosition[4];
static GLfloat lightColor[] = {0.8, 1.0, 0.8, 1.0}; /* green-tinted */
static GLfloat skinColor[] = {0.1, 1.0, 0.1, 1.0}, eyeColor[] = {1.0, 0.2, 0.2, 1.0};
/* *INDENT-ON* */


enum {
  X, Y, Z, W
};
enum {
  A, B, C, D
};

/* Create a matrix that will project the desired shadow. */
void
shadowMatrix(GLfloat shadowMat[4][4],
  GLfloat groundplane[4],
  GLfloat lightpos[4])
{
  GLfloat dot;

  /* Find dot product between light position vector and ground plane normal. */
  dot = groundplane[X] * lightpos[X] +
    groundplane[Y] * lightpos[Y] +
    groundplane[Z] * lightpos[Z] +
    groundplane[W] * lightpos[W];

  shadowMat[0][0] = dot - lightpos[X] * groundplane[X];
  shadowMat[1][0] = 0.f - lightpos[X] * groundplane[Y];
  shadowMat[2][0] = 0.f - lightpos[X] * groundplane[Z];
  shadowMat[3][0] = 0.f - lightpos[X] * groundplane[W];

  shadowMat[X][1] = 0.f - lightpos[Y] * groundplane[X];
  shadowMat[1][1] = dot - lightpos[Y] * groundplane[Y];
  shadowMat[2][1] = 0.f - lightpos[Y] * groundplane[Z];
  shadowMat[3][1] = 0.f - lightpos[Y] * groundplane[W];

  shadowMat[X][2] = 0.f - lightpos[Z] * groundplane[X];
  shadowMat[1][2] = 0.f - lightpos[Z] * groundplane[Y];
  shadowMat[2][2] = dot - lightpos[Z] * groundplane[Z];
  shadowMat[3][2] = 0.f - lightpos[Z] * groundplane[W];

  shadowMat[X][3] = 0.f - lightpos[W] * groundplane[X];
  shadowMat[1][3] = 0.f - lightpos[W] * groundplane[Y];
  shadowMat[2][3] = 0.f - lightpos[W] * groundplane[Z];
  shadowMat[3][3] = dot - lightpos[W] * groundplane[W];

}

/* Find the plane equation given 3 points. */
void
findPlane(GLfloat plane[4],
  GLfloat v0[3], GLfloat v1[3], GLfloat v2[3])
{
  GLfloat vec0[3], vec1[3];

  /* Need 2 vectors to find cross product. */
  vec0[X] = v1[X] - v0[X];
  vec0[Y] = v1[Y] - v0[Y];
  vec0[Z] = v1[Z] - v0[Z];

  vec1[X] = v2[X] - v0[X];
  vec1[Y] = v2[Y] - v0[Y];
  vec1[Z] = v2[Z] - v0[Z];

  /* find cross product to get A, B, and C of plane equation */
  plane[A] = vec0[Y] * vec1[Z] - vec0[Z] * vec1[Y];
  plane[B] = -(vec0[X] * vec1[Z] - vec0[Z] * vec1[X]);
  plane[C] = vec0[X] * vec1[Y] - vec0[Y] * vec1[X];

  plane[D] = -(plane[A] * v0[X] + plane[B] * v0[Y] + plane[C] * v0[Z]);
}


static GLfloat floorVertices[4][3] = {
  { -20.0, 0.0, 20.0 },
  { 20.0, 0.0, 20.0 },
  { 20.0, 0.0, -20.0 },
  { -20.0, 0.0, -20.0 },
};


static GLfloat floorPlane[4];
static GLfloat floorShadow[4][4];

static void
redraw(int object)
{
  int start, end;

  /* Clear; default stencil clears to zero. */
  //if ((stencilReflection && renderReflection) || (stencilShadow && renderShadow)) {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  //} else {
    /* Avoid clearing stencil when not using it. */
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //}

  /* Reposition the light source. */
  //lightPosition[0] = 12*cos(lightAngle);
  //lightPosition[1] = lightHeight;
  //lightPosition[2] = 12*sin(lightAngle);
  //if (directionalLight) {
  //  lightPosition[3] = 0.0;
  //} else {
  //  lightPosition[3] = 1.0;
  //}

  shadowMatrix(floorShadow, floorPlane, light_Position);

  glPushMatrix();
   
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);


    if (renderShadow) {
      if (stencilShadow) {
	/* Draw the floor with stencil value 3.  This helps us only 
	   draw the shadow once per floor pixel (and only on the
	   floor pixels). */
        //glEnable(GL_STENCIL_TEST);
        //glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
        //glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
      }
    }
    if (renderDinosaur) {
    }

    if (renderShadow) {

      /* Render the projected shadow. */

      if (stencilShadow) {

        /* Now, only render where stencil is set above 2 (ie, 3 where
	   the top floor is).  Update stencil with 2 where the shadow
	   gets drawn so we don't redraw (and accidently reblend) the
	   shadow). */
        glStencilFunc(GL_LESS, 2, 0xffffffff);  /* draw if ==1 */
        glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
      }

      /* To eliminate depth buffer artifacts, we use polygon offset
	 to raise the depth of the projected shadow slightly so
	 that it does not depth buffer alias with the floor. */
      if (offsetShadow) {
	switch (polygonOffsetVersion) {
	case EXTENSION:
#ifdef GL_EXT_polygon_offset
	  glEnable(GL_POLYGON_OFFSET_EXT);
	  break;
#endif
#ifdef GL_VERSION_1_1
	case ONE_DOT_ONE:
          glEnable(GL_POLYGON_OFFSET_FILL);
	  break;
#endif
	case MISSING:
	  /* Oh well. */
	  break;
	}
      }

      /* Render 50% black shadow color on top of whatever the
         floor appareance is. */
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glDisable(GL_LIGHTING);  /* Force the 50% black. */
      glColor4f(0.0, 0.0, 0.0, 0.5);

      glPushMatrix();
	/* Project the shadow. */
        glMultMatrixf((GLfloat *) floorShadow);
        //drawDinosaur();
        //glTranslatef(0.0, 1.25, 0.0);
        // Mini Tower Defense TBQH
		if(object == 1)
		{
			glScaled(.08, .06, .08);
			glRotated(83, 0.0, 1.0, 0.0);
		    glCallList(vtd_dl::teslaDL);
		}
		else if(object == 2)
		{
			glScaled(0.15, 0.15, 0.15);
			glCallList(vtd_dl::turretDL);
		}
		else if(object == 3)
		{
			 glScaled(0.03, 0.03, 0.03);
			 glRotated(90, 0.0, 1.0, 0.0);
			 glCallList(vtd_dl::backtrackDL);
		}
		else if(object == 4)
		{
			glScaled(0.035, 0.035, 0.035);
			glCallList(vtd_dl::fanDL);
		}
		else if(object == 5)
		{
			glScalef(0.5, 0.5, 0.5);
			glCallList(vtd_dl::lockDL);
		}
		else if(object == 6)
		{
			glScaled(.3,.2,.3);
			glCallList(vtd_dl::blkhatDL);			
		}
		else if(object == 7)
		{
		    glScaled(0.1, 0.1, 0.1);
			glRotatef(-90, 0.0, 1.0, 0.0);
		    glCallList(vtd_dl::wormDL);
		}
		else if(object == 8)
		{
		    glScaled(0.25, 0.25, 0.25);
		    glCallList(vtd_dl::virusDL);
		}
		else if(object == 9)
		{
			glScaled(0.20, 0.20, 0.20);
			glCallList(vtd_dl::forkbDL);
		}
		else if(object == 10)
		{
			glScaled(0.10, 0.10, 0.10);
			glCallList(vtd_dl::trojanDL);
		}
        //glRotated(83, 0.0, 1.0, 0.0);
		//drawVirus1();
      glPopMatrix();

      glDisable(GL_BLEND);
      glEnable(GL_LIGHTING);

      if (offsetShadow) {
	switch (polygonOffsetVersion) {
#ifdef GL_EXT_polygon_offset
	case EXTENSION:
	  glDisable(GL_POLYGON_OFFSET_EXT);
	  break;
#endif
#ifdef GL_VERSION_1_1
	case ONE_DOT_ONE:
          glDisable(GL_POLYGON_OFFSET_FILL);
	  break;
#endif
	case MISSING:
	  /* Oh well. */
	  break;
	}
      }
      if (stencilShadow) {
        glDisable(GL_STENCIL_TEST);
      }
    }


  glPopMatrix();

}


enum {
  M_NONE, M_MOTION, M_LIGHT, M_TEXTURE, M_SHADOWS, M_REFLECTION, M_DINOSAUR,
  M_STENCIL_REFLECTION, M_STENCIL_SHADOW, M_OFFSET_SHADOW,
  M_POSITIONAL, M_DIRECTIONAL, M_PERFORMANCE
};


static int
supportsOneDotOne(void)
{
  const char *version;
  int major, minor;

  version = (char *) glGetString(GL_VERSION);
  if (sscanf(version, "%d.%d", &major, &minor) == 2)
    return major >= 1 && minor >= 1;
  return 0;            /* OpenGL version string malformed! */
}

void draw_shadow(int shad)
{
	int x = 0;
#ifdef GL_VERSION_1_1
  if (supportsOneDotOne() && !forceExtension) {
    polygonOffsetVersion = ONE_DOT_ONE;
    glPolygonOffset(-2.0, -1.0);
  } else
#endif
  {
#ifdef GL_EXT_polygon_offset
  /* check for the polygon offset extension */
  if (glutExtensionSupported("GL_EXT_polygon_offset")) {
    polygonOffsetVersion = EXTENSION;
    glPolygonOffsetEXT(-0.1, -0.002);
  } else 
#endif
    {
      polygonOffsetVersion = MISSING;
      printf("\ndinoshine: Missing polygon offset.\n");
      printf("           Expect shadow depth aliasing artifacts.\n\n");
    }
  }

  //glEnable(GL_CULL_FACE);
  //glEnable(GL_DEPTH_TEST);
  //glEnable(GL_TEXTURE_2D);
  //glLineWidth(3.0);
  //glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
  //glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
  //glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1);
  //glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
  //glEnable(GL_LIGHT0);
  //glEnable(GL_LIGHTING);
	findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);
	redraw(shad);
}
