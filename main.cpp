#include "GL/freeglut.h"
#include "GL/gl.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

unsigned int textures[1];

void LoadTextures() {
    //AUX_RGBImageRec *texture1 = auxDIBImageLoadA("Untitled.bmp");
    SDL_Surface *texture1 = IMG_Load("Untitled.png");
    //texture1 = SDL_LoadBMP("Untitled.bmp");
    
    glGenTextures(1, &textures[0]);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture1->w, texture1->h, 0, 
            GL_RGB, GL_UNSIGNED_BYTE, texture1->pixels);
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
        glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
        glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
        glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glEnd();

    glFlush();
}

void Initsialaize() {
    LoadTextures();
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0, 4.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 12");
    
    glutDisplayFunc(Draw);
    Initsialaize();
    glutMainLoop();
    
    return 0;
}