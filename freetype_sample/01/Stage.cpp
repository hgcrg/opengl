#include "Stage.h"
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/fttypes.h>
#include FT_TRUETYPE_IDS_H
#include <FreeImage.h>
#include <iostream>
Stage::Stage()
{

}


Stage::~Stage()
{

}

void Stage::Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w/h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void Stage::Init()
{
    FreeImage_Initialise(true);
    FIBITMAP * bitmap = FreeImage_Load(FIF_JPEG, "/home/cc/Images/1.jpg");
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE  * data = FreeImage_GetBits(bitmap);
    glGenTextures(1, &m_tex);
    glBindTexture(GL_TEXTURE_2D, m_tex);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // 线形滤波
    glEnable(GL_TEXTURE_2D);
}


void Stage::Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glLoadIdentity();
    glTranslatef(0.0, 0.0, -30.0f);
    static float temp = 0.0f;
    glRotatef(temp, 0.0, 1.0, 0.0f);
    temp += 0.1f;
    glBindTexture(GL_TEXTURE_2D, m_tex);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);     glVertex3f(-10.0f,-10.0f,  0.0f);
    glTexCoord2f(0.0f, 1.0f);     glVertex3f(10.0f, -10.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);     glVertex3f(10.0f,10.0f,0.0f);
    glTexCoord2f(1.0f, 0.0f);     glVertex3f(-10.0f,10.0f,0.0f);
    glEnd();
}

