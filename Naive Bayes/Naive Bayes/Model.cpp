//
//  Model.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/25/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "Model.hpp"
#include <math.h>

bool Model::Train(ImageSet set, int smooth_factor) {
    int feature_count[CLASSES][IMAGE_SIZE][IMAGE_SIZE] = {{{ 0 }}};
    
    if (set.Size() == MISMATCHED_DIM) {
        return false;
    }
    
    Image training_image;
    
    for (int i = 0; i < set.Size(); ++i) {
        class_count[set.GetDescriptorAt(i)]++;
        training_image = set.GetImageAt(i);
        
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            for (int k = 0; k < IMAGE_SIZE; ++k) {
                if (training_image.GetValue(j, k) == BLACK_CHAR) {
                    feature_count[set.GetDescriptorAt(i)][j][k]++;
                }
            }
        }
    }
    
    for (int i = 0; i < CLASSES; ++i) {
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            for (int k = 0; k < IMAGE_SIZE; ++k) {
                int features_seen = feature_count[i][j][k];
                int count = class_count[i];
                model[i][j][k] = log((features_seen + smooth_factor) / (count + 2 * smooth_factor));
            }
        }
    }
    
    return true;
}
