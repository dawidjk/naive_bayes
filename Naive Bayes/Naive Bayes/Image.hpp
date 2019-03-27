//
//  Image.hpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/22/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include <string>

#define IMAGE_SIZE 28
#define BLACK_CHAR '#'
#define GREY_CHAR '+'

class Image {
private:
    char image[IMAGE_SIZE][IMAGE_SIZE];
    
public:
    void LoadImage(std::string line[IMAGE_SIZE], bool black_white);
    char GetValue(int x_index, int y_index);
};

#endif /* Image_hpp */
