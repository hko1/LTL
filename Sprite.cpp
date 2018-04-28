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

Sprite::Sprite(const std::string &imagePath) : imagePath(imagePath) {
    surface = IMG_Load(imagePath.c_str());
    loadTexture();
}

Sprite::~Sprite() {
    SDL_FreeSurface(surface);
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

void Sprite::draw() {
    glBindTexture( GL_TEXTURE_2D, glId );
    glBegin(GL_QUADS);
    // vertex 1
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    // vertex 2
    glTexCoord2f(1.0, 1.0);
    glVertex3f( 1.0f, -1.0f, 0.0f);
    // vertex 3
    glTexCoord2f(1.0, 0.0);
    glVertex3f( 1.0f,  1.0f, 0.0f);
    // vertex 4
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.0f,  1.0f, 0.0f);
    glEnd();
}
