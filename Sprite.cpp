     /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: Bug Buggy
 * 
 * Created on 29. April 2018, 00:59
 */

#include "Sprite.h"
#include "Image.h"

Sprite::Sprite(const std::string &imagePath) {
    x=0;
    y=0; 
    image=new Image(imagePath);
}
void Sprite::draw(){
    image->draw(x,y);
}


Sprite::~Sprite() {
    delete image;
}