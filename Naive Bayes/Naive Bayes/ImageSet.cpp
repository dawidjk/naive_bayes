//
//  ImageSet.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/22/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "ImageSet.hpp"
#include "FileIO.hpp"

unsigned long ImageSet::LoadSet(std::string file_location, bool black_white) {
    FileIO file_io;
    
    if (!file_io.OpenFileRead(file_location)) {
        return FILE_NOT_OPEN;
    }
    
    std::string image_line = file_io.ReadLine();
    std::string image_data[IMAGE_SIZE] = {""};
    int line_count = 0;
    
    while (image_line != "") {
        image_data[line_count] = image_line;
        line_count++;
        
        if (line_count == IMAGE_SIZE) {
            Image image;
            image.LoadImage(image_data, black_white);
            image_set.push_back(image);
            
            line_count = 0;
        }
        
        image_line = file_io.ReadLine();
    }
    
    file_io.Close();
    
    return image_set.size();
}

unsigned long ImageSet::LoadDescriptors(std::string file_location) {
    FileIO file_io;
    
    if (!file_io.OpenFileRead(file_location)) {
        return FILE_NOT_OPEN;
    }
    
    int descriptor = file_io.ReadInt();
    
    while (descriptor != -1) {
        image_descriptor.push_back(descriptor);
        descriptor = file_io.ReadInt();
    }
    
    return image_descriptor.size();
}

unsigned long ImageSet::Size() {
    if (image_set.size() != image_descriptor.size()) {
        return MISMATCHED_DIM;
    } else {
        return image_set.size();
    }
}

Image ImageSet::GetImageAt(int index) {
    return image_set.at(index);
}

int ImageSet::GetDescriptorAt(int index) {
    return image_descriptor.at(index);
}
