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

#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <SDL.h>
#include <SDL_opengl.h>

class Sprite {
public:
    Sprite(const std::string &imagePath);
    virtual ~Sprite();
    
    void draw();
    
private:
    const std::string imagePath;
    SDL_Surface* surface;
    GLuint glId;
    
    void loadTexture();
};

#endif /* SPRITE_H */

