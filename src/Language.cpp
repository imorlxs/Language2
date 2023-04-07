/*
 * Metodologí­a de la Programación: Language2
 * Curso 2022/2023
 */

/* 
 * @file   Language.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 * @author Francisco Javier Caceres Martin <javicaceres@correo.ugr.es>
 *
 */

#include "Language.h"

using namespace std;

const string Language::MAGIC_STRING_T = "MP-LANGUAGE-T-1.0";

Language::Language() {
    _size = 0;
    _languageId = "unknown";
}

Language::Language(int numberBigrams) {
    if (numberBigrams >= 0 && numberBigrams < DIM_VECTOR_BIGRAM_FREQ) {
        _size = numberBigrams;
        _languageId = "unknown";
    } else {
        throw std::out_of_range(std::string("Language::Language(int numberBigrams) ")
                + "invalid number " + std::to_string(numberBigrams));
    }
}

string Language::getLanguageId() const {
    return _languageId;
}

void Language::setLanguageId(string id) {
    _languageId = id;
}

BigramFreq Language::at(int index) const {
    if (index < _size && index >= 0) {
        return _vectorBigramFreq[index];
    } else {
        throw std::out_of_range(std::string("Language::at(int index) const ")
                + "invalid position " + std::to_string(index));
    }
}

BigramFreq Language::at(int index) {
    if (index < _size && index >= 0) {
        return _vectorBigramFreq[index];
    } else {
        throw std::out_of_range(std::string("Language::at(int index) ")
                + "invalid position " + std::to_string(index));
    }
}

int Language::getSize() const {
    return _size;
}

int Language::findBigram(Bigram &bigram) {
    for (int i = 0; i < _size; i++) {
        if (_vectorBigramFreq[i].getBigram().getText() == bigram.getText()) {
            return i;
        }
    }
    return -1;
}

string Language::toString() {
    string size = to_string(_size);
    size += '\n';
    for (int i = 0; i < _size; i++) {
        size += _vectorBigramFreq[i].toString();
        size += '\n';
    }
    size.pop_back();
    return size;
}

void Language::sort() {
    for (int i = 0; i < _size; i++) {
        for (int j = _size - 1; j > i; j--) {
            if (_vectorBigramFreq[j].getFrequency() > _vectorBigramFreq[j - 1].getFrequency()) {
                this->swap(j, j - 1);
            } else if (_vectorBigramFreq[j].getFrequency() == _vectorBigramFreq[j - 1].getFrequency()) {
                if (_vectorBigramFreq[j].getBigram().getText() < _vectorBigramFreq[j - 1].getBigram().getText()) {
                    this->swap(j, j - 1);
                }
            }
        }
    }
}

void Language::save(char fileName[]) {
    ofstream fout;
    fout.open(fileName);
    if (fout) {
        fout << MAGIC_STRING_T << endl;
        fout << _languageId << endl;
        fout << this->toString();
        if (!fout) {
            throw std::ios_base::failure(string("error_de_escritura_del_fichero\n"));
        }
        fout.close();
    } else {
        throw std::ios_base::failure(string("error_de_apertura_del_fichero_save\n"));
    }
}

void Language::load(char fileName[]) {
    ifstream fin;
    string magic_string;
    int frequency;
    string text;
    fin.open(fileName);
    if (fin) {
        fin >> magic_string;
        if (magic_string == MAGIC_STRING_T) {
            fin >> _languageId;
            fin >> _size;
            for (int i = 0; i < _size; i++) {
                fin >> text;
                fin >> frequency;
                Bigram bigram(text);
                _vectorBigramFreq[i].setBigram(bigram);
                _vectorBigramFreq[i].setFrequency(frequency);
            }
        } else {
            throw std::invalid_argument(string("The magic word isn't correct\n"));
        }


        if (!fin) {
            throw std::ios_base::failure(string("error_de_lectura_del_fichero\n"));
        }
        fin.close();
    } else {
        throw std::ios_base::failure(string("error_de_apertura_del_fichero_load\n"));
    }
}

void Language::append(BigramFreq bigramFreq) {
    Bigram bigram = bigramFreq.getBigram();
    int index = this->findBigram(bigram);
    int freq = bigramFreq.getFrequency();
    if (index >= 0) {
        _vectorBigramFreq[index].setFrequency(freq + _vectorBigramFreq[index].getFrequency());
    } else {
        if (_size < DIM_VECTOR_BIGRAM_FREQ) {
            _size++;
            _vectorBigramFreq[_size - 1].setBigram(bigram);
            _vectorBigramFreq[_size - 1].setFrequency(freq);
        } else {
            throw std::out_of_range(string("The array is full\n"));
        }
    }
}

void Language::join(Language language) {
    for (int i = 0; i < language.getSize(); i++) {
        this->append(language.at(i));
    }
}

void Language::swap(int first, int second) {
    BigramFreq aux;
    aux = _vectorBigramFreq[second];
    _vectorBigramFreq[second] = _vectorBigramFreq[first];
    _vectorBigramFreq[first] = aux;
}
