//
//  FileReader.cpp
//  Sudoku-Solver
//
//  Created by David Kluszczynski on 3/10/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

// Data Directory:
// /Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata

#include "FileIO.hpp"

bool FileIO::OpenFileRead(std::string file_name) {
    FileIO::read_file.open(file_name);
    
    return FileIO::read_file.is_open();
}

std::string FileIO::ReadLine() {
    if (FileIO::read_file.is_open()) {
        std::string line;
        
        if (getline(read_file, line)) {
            return line;
        }
        
        FileIO::read_file.close();
    }
    
    return "";
}

int FileIO::ReadInt() {
    if (read_file.is_open()) {
        std::string value;
        
        if (!read_file.eof()) {
            read_file >> value;
            
            return std::stoi(value);
        }
        
        FileIO::read_file.close();
    }
    
    return -1;
}

double FileIO::ReadDouble() {
    if (read_file.is_open()) {
        std::string value;
        
        if (!read_file.eof()) {
            read_file >> value;
            
            return std::stod(value);
        }
        
        FileIO::read_file.close();
    }
    
    return -1;
}

bool FileIO::OpenFileWrite(std::string file_name) {
    FileIO::write_file.open(file_name);
    
    return FileIO::write_file.is_open();
}

std::ofstream& FileIO::GetWriteFile() {
    return FileIO::write_file;
}

bool FileIO::Close() {
    write_file.flush();
    
    read_file.close();
    write_file.close();
    
    return write_file.is_open() && read_file.is_open();
}
