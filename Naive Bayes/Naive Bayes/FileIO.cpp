//
//  FileReader.cpp
//  Sudoku-Solver
//
//  Created by David Kluszczynski on 3/10/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

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
        if (!read_file.eof()) {
            int value;
            read_file >> value;
            return value;
        }
        
        FileIO::read_file.close();
    }
    
    return -1;
}

double FileIO::ReadDouble() {
    if (read_file.is_open()) {
        if (!read_file.eof()) {
            double value;
            read_file >> value;
            return value;
        }
        
        FileIO::read_file.close();
    }
    
    return -1;
}

bool FileIO::OpenFileWrite(std::string file_name) {
    FileIO::write_file.open(file_name, std::ios_base::app);
    
    return FileIO::write_file.is_open();
}

void FileIO::SaveModel(Model model) {
    if (FileIO::write_file.is_open()) {
        write_file << model;
        std::cout << std::endl << "Model saved" << std::endl;
    }
}

bool FileIO::Close() {
    read_file.close();
    write_file.close();
    
    return write_file.is_open() && read_file.is_open();
}
