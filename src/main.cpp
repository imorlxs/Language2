/*
 * Metodologí­a de la Programación: Language2
 * Curso 2022/2023
 */

/* 
 * @file   main.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 * @author Francisco Javier Caceres Martin <javicaceres@correo.ugr.es>
 *
 */

#include <iostream>
#include <fstream>
#include "Language.h"
using namespace std;

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << endl;
    outputStream << "language2 <file1.bgr> [<file2.bgr> ... <filen.bgr>] <outputFile.bgr> " << endl;
}

/**
 * This program reads an undefined number of Language objects from the files
 * passed as parameters to main(). It obtains as result the union of all the 
 * input Language objects. The result is then sorted by decreasing order of 
 * frequency and alphabetical order of bigrams when there is any tie in 
 * frequencies. Finally the resulting Language is saved in an output file. The 
 * program must have at least an input file and an output file. 
 * The output Language will have as language identifier, the one of the first
 * file (<file1.bgr>). If an input file <file*.bgr> has a language identifier
 * different from the one of the first file (<file1.bgr>), then it will not
 * be included in the union.
 * Running example:
 * > language2 <file1.bgr> [<file2.bgr> ... <filen.bgr>] <outputFile.bgr> 
 */
int main(int argc, char* argv[]) {
    
}

