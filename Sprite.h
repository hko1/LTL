/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.h
 * Author: Bug Buggy
 *
 * Created on 29. April 2018, 00:59
 */ 
    
#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "Image.h"

class Sprite {
public:
    Sprite(const std::string &imagePath);
    virtual ~Sprite();
        
    void draw();
protected:   
    float x,y;
    Image *image;

};

#endif /* SPRITE_H */

