/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: daniel
 * 
 * Created on April 28, 2018, 11:07 PM
 */

#include <SDL_image.h>

#include "Sprite.h"

Sprite::Sprite(const std::string &imagePath) :
        imagePath(imagePath),
        scale_(1.0)
{
    surface = IMG_Load(imagePath.c_str());
    loadTexture();
}

Sprite::~Sprite() {
    SDL_FreeSurface(surface);
}

GLuint Sprite::width() {
    return scale()*surface->w;
}
GLuint Sprite::height() {
    return scale()*surface->h;
}

GLfloat Sprite::scale() {
    return scale_;
}
void Sprite::set_scale(GLfloat scale) {
    scale_ = scale;
}

void Sprite::loadTexture() {
    glGenTextures(1, &glId);
    glBindTexture(GL_TEXTURE_2D, glId);
    int Mode = GL_RGB;
    if(surface->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, Mode,
            surface->w, surface->h, 0,
            Mode, GL_UNSIGNED_BYTE, surface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Sprite::draw(float x, float y) {
    glBindTexture(GL_TEXTURE_2D, glId);
    glBegin(GL_QUADS);
    float w5 = width()*0.5f;
    float h5 = height()*0.5f;
    // vertex 1
    glTexCoord2f(0.0, 1.0);
    glVertex3f(
            x - w5,
            y - h5, 0.0f);
    // vertex 2
    glTexCoord2f(1.0, 1.0);
    glVertex3f(
            x + w5,
            y - h5, 0.0f);
    // vertex 3
    glTexCoord2f(1.0, 0.0);
    glVertex3f(
            x + w5,
            y + h5, 0.0f);
    // vertex 4
    glTexCoord2f(0.0, 0.0);
    glVertex3f(
            x - w5,
            y + h5, 0.0f);
    glEnd();
}
