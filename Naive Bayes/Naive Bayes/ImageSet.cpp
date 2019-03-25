//
//  ImageSet.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/22/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "ImageSet.hpp"

bool ImageSet::LoadSet(std::string file_location) {
    FileIO file_io;
    file_io.OpenFileRead(file_location);
    
    std::string image_line = file_io.ReadLine();
    int line_count = 0;
    std::string image_data[IMAGE_SIZE] = {""};
    
    while (image_line != "") {
        image_data[line_count] = image_line;
        line_count++;
        
        if (line_count == IMAGE_SIZE) {
            Image image;
            image.LoadImage(image_data);
            ImageSet.push_back(image);
            
            line_count = 0;
        }
        
        image_line = file_io.ReadLine();
    }
    
    if (line_count == 0) {
        return true;
    }
    
    return false;
}
