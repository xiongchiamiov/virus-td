#include "lighting.h"
materialStruct RedFlat = {
  {0.3, 0.0, 0.0, 1.0},
  {0.9, 0.0, 0.0, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.0}
};

materialStruct GreenShiny = {
  {0.0, 0.3, 0.0, 1.0},
  {0.0, 0.9, 0.0, 1.0},
  {0.2, 0.8, 0.2, 1.0},
  {6.0}
};

materialStruct BlueFlat = {
  {0.0, 0.0, 0.3, 1.0},
  {0.0, 0.0, 0.9, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.0}
};

materialStruct Metal = {
{0.33, 0.22, 0.03, 1.0},
{0.78, 0.57, 0.11, 1.0},
{0.99, 0.91, 0.81, 1.0},
{27.8}
};

materialStruct Exp = {
  {0.0, 0.0, 0.5, 1.0}, 
  {0.2, 0.2, 0.7, 1.0},
  {0.6, 0.4, 0.9, 1.0},
  {120.0}
};
materialStruct Exp2 = {
  {1.0, 0.0, 0.0, 1.0}, 
  {0.2, 1.0, 0.2, 1.0},
  {0.0, 0.2, 1.0, 1.0},
  {20.0}
};
materialStruct Grey = {
  {0.2, 0.2, 0.2, 1.0}, 
  {0.2, 0.2, 0.2, 1.0},
  {0.3, 0.3, 0.3, 1.0},
  {2.0}
};
materialStruct Black = {
  {0.08, 0.08, 0.08, 1.0}, 
  {0.08, 0.08, 0.08, 1.0},
  {0.08, 0.08, 0.08, 1.0},
  {0.0}
};
materialStruct Teal = {
  {0.15, 0.3, 0.33, 1.0}, 
  {0.5, 0.8, 0.89, 1.0},
  {0.4, 0.87, 0.95, 1.0},
  {3.0}
};
materialStruct Purple = {
  {0.4, 0.1, 0.4, 1.0}, 
  {0.5, 0.6, 0.05, 1.0},
  {0.8, 0.8, 0.2, 1.0},
  {4.0}
};
materialStruct Fuschia = {
  {0.7, 0.4, 0.55, 1.0}, 
  {0.8, 0.3, 0.7, 1.0},
  {0.9, 0.5, 0.9, 1.0},
  {3.0}
};
materialStruct FieryOrange = {
  {0.43, 0.2, 0.0, 1.0}, 
  {0.73, 0.36, 0.3, 1.0},
  {0.93, 0.45, 0.1, 1.0},
  {3.0}
};
materialStruct White = {
  {1.0, 1.0, 1.0, 1.0}, 
  {1.0, 1.0, 1.0, 1.0},
  {1.0, 1.0, 1.0, 1.0},
  {0.0}
};

materialStruct PureRed = {
  {1.0, 0.0, 0.0, 1.0}, 
  {0.0, 0.0, 0.0, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.0}
};

materialStruct Brown = {
  {0.4, 0.2, 0.1, 1.0}, 
  {0.0, 0.0, 0.0, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.0}
};

materialStruct ShinyMetal = {
  {0.4, 0.4, 0.4, 1.0}, 
  {1.0, 1.0, 1.0, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {1.0}
};

materialStruct DarkGrey = {
  {0.2, 0.2, 0.2, 1.0}, 
  {0.0, 0.0, 0.0, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.8}
};

materialStruct DarkDarkGrey = {
  {0.1, 0.1, 0.1, 1.0}, 
  {0.0, 0.0, 0.0, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.8}
};

materialStruct Yellow = {
  {0.5, 0.5, 0.0, 1.0}, 
  {0.9, 0.9, 0.9, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.2}
};

materialStruct Grid = {
  {0.08, 0.08, 0.08, 1.0}, 
  {0.08, 0.08, 0.08, 1.0},
  {0.12, 0.12, 0.12, 1.0},
  {120.0}
};

materialStruct EnemyGrid = {
  {0.3, 0.0, 0.0, 1.0},
  {0.9, 0.0, 0.0, 1.0},
  {0.4, 0.0, 0.0, 1.0},
  {120.0}
};

materialStruct PlayerGrid = {
  {0.0, 0.0, 0.2, 1.0},
  {0.0, 0.0, 0.8, 1.0},
  {0.0, 0.0, 0.4, 1.0},
  {120.0}
};

//sets up a specific material
void setMaterial(materialStruct materials) {
  glMaterialfv(GL_FRONT, GL_AMBIENT, materials.ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, materials.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, materials.specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, materials.shininess);
}