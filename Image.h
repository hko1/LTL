/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.h
 * Author: daniel
 *
 * Created on April 28, 2018, 11:07 PM
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <string>

#include <SDL.h>
#include <SDL_opengl.h>

class Image {
public:
    Image(const std::string &imagePath);
    virtual ~Image();
    
    void draw(float x, float y);
    
    GLuint width();
    GLuint height();
    
    GLfloat scale();
    void set_scale(GLfloat scale);
    
private:
    const std::string imagePath;
    SDL_Surface* surface;
    GLuint glId;
    GLfloat scale_;
    
    void loadTexture();
};

#endif /* IMAGE_H */

