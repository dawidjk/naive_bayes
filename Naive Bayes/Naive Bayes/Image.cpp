//
//  Image.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/22/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "Image.hpp"

void Image::LoadImage(std::string line_arr[IMAGE_SIZE]) {
    for (int i = 0; i < IMAGE_SIZE; ++i) {
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            image[i][j] = line_arr[i][j];
        }
    }
}
