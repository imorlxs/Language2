/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

/* 
 * File:   BigramFreq.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 * @author Francisco Javier Caceres Martin <javicaceres@correo.ugr.es>
 *
 */

#include "BigramFreq.h"
#include <string>
#include <cstring>
#include <iostream>

 BigramFreq::BigramFreq(){
     _frequency = 0;
}
 Bigram BigramFreq::getBigram(){
    return _bigram;
}

int BigramFreq::getFrequency() const{
    return _frequency;
}

void BigramFreq::setBigram(Bigram& bigram){
    _bigram = bigram;
    
}

void BigramFreq::setFrequency(int frequency){
    if (frequency > 0){
    _frequency=frequency;
    } else{
        throw std::out_of_range(std::string("void BigramFreq::setFrequency(int frequency) ")
                + "invalid position " + std::to_string(frequency));
    }
}
std::string BigramFreq::toString(){
    return _bigram.toString() + " " + std::to_string(_frequency);
}

void BigramFreq::toUpper(){
    _bigram.toUpper();
}




