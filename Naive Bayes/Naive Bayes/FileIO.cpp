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

bool FileIO::OpenFileWrite(std::string file_name) {
    FileIO::write_file.open(file_name, std::ios_base::app);
    
    return FileIO::write_file.is_open();
}

void FileIO::WriteBoard(/*Make sure to define*/) {
    if (FileIO::write_file.is_open()) {
        //FileIO::write_file << sudoku_board;
        //std::cout << std::endl << "Solution saved" << std::endl;
    } else {
        //std::cout << sudoku_board;
    }
}

bool FileIO::Close() {
    read_file.close();
    write_file.close();
    
    return write_file.is_open() && read_file.is_open();
}
