/*
 * Metodologí­a de la Programación: Language2
 * Curso 2022/2023
 */

/* 
 * @file   Bigram.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 * @author Francisco Javier Caceres Martin <javicaceres@correo.ugr.es>
 *
 */


#include <string>
#include <cstring>
#include "Bigram.h" 

Bigram::Bigram(const std::string& text) {
    if (text.size() == 2) {
        strcpy(_text, text.c_str());
    } else {
        strcpy(_text, "__");
    }
}

Bigram::Bigram(char first, char second) {
    _text[0] = first;
    _text[1] = second;
    _text[2] = '\0';

}

Bigram::Bigram(const char text[]) {
    if (strlen(text) == 2) {
        strcpy(_text, text);
    } else {
        strcpy(_text, "__");
    }
}


std::string Bigram::getText() const {
    std::string text(_text);
    return text;
}

std::string Bigram::toString() const {
    std::string text(_text);
    return text;
}

const char& Bigram::at(int index) const {
    if (index < 0 || index > 2) {
        throw std::out_of_range(std::string("const char& Bigram::at(int index) const: ")
                + "invalid position " + std::to_string(index));
    } else {
        return _text[index];
    }
}

char& Bigram::at(int index) {
    if (index < 0 || index > 1) {
        throw std::out_of_range(std::string("char& Bigram::at(int index): ")
                + "invalid position " + std::to_string(index));
    } else {
        return _text[index];
    }

}

void Bigram::toUpper() {
    int asciidiff = 'a' - 'A';
   // int isodiff = 'à' - 'À';   <----- PARA PASAR A MAYÚSCULAS LOS CARÁCTERES ISO, DESCOMENTAR PARA IMPLEMENTAR
    for (int i = 0; i < 2; i++) {
        if (_text[i] >= 'a' && _text[i] <= 'z') {
            _text[i] = _text[i] - asciidiff;
        }
        // <------ PARA PASAR A MAYÚSCULAS LOS CARÁCTERES ISO, DESCOMENTAR PARA IMPLEMENTAR
        // else if (_text[i] >= 'à' && _text[i] <= 'ü') { 
           // _text[i] = _text[i] - isodiff;
        //}
    }

}

bool isValidCharacter(char character, const std::string& validCharacters) {
    for (int i = 0; i < validCharacters.length(); i++) {
        if (validCharacters[i] == character)
            return true;
    }
    return false;
}

