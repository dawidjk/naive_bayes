//
//  Image.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/22/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "Image.hpp"

void Image::LoadImage(std::string line_arr[IMAGE_SIZE], bool black_white) {
    for (int i = 0; i < IMAGE_SIZE; ++i) {
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            char pixel = line_arr[i][j];
            
            if (black_white && pixel == GREY_CHAR) {
                pixel = BLACK_CHAR;
            }
            
            image[i][j] = pixel;
        }
    }
}

char Image::GetValue(int x_index, int y_index) {
    return image[x_index][y_index];
}
