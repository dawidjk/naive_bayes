//
//  FileReader.hpp
//  Sudoku-Solver
//
//  Created by David Kluszczynski on 3/10/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#ifndef FileIO_hpp
#define FileIO_hpp

#include <string>
#include <fstream>
#include <iostream>

class FileIO {
private:
    std::ifstream read_file;
    std::ofstream write_file;
    
public:
    bool OpenFileRead(std::string file_name);
    std::string ReadLine();
    bool OpenFileWrite(std::string file_name);
    void WriteBoard(/*Define Type*/);
    bool Close();
    
};

#endif /* FileIO_hpp */
