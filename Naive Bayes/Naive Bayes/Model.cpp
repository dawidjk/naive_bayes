//
//  Model.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/25/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "Model.hpp"
#include <math.h>
#include "FileIO.hpp"

bool Model::Train(ImageSet set, int smooth_factor) {
    int feature_count[CLASSES][IMAGE_SIZE][IMAGE_SIZE] = {{{ 0 }}};
    
    if (set.Size() == MISMATCHED_DIM) {
        return false;
    }
    
    for (int i = 0; i < set.Size(); ++i) {
        class_count[set.GetDescriptorAt(i)]++;
        Image training_image = set.GetImageAt(i);
        
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
                model[i][j][k] = ((double) (features_seen + smooth_factor)) / ((double) (count + 2 * smooth_factor));
            }
        }
    }
    
    return true;
}

int Model::Evaluate(Image image) {
    double class_post_prob[CLASSES] = { 0 };
    
    for (int i = 0; i < CLASSES; ++i) {
        double probability = 0;
        
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            for (int k = 0; k < IMAGE_SIZE; ++k) {
                if (image.GetValue(j, k) == BLACK_CHAR) {
                    probability += log(model[i][j][k]);
                } else {
                    probability += log(1 - model[i][j][k]);
                }
            }
        }
        
        class_post_prob[i] = log(class_count[i]) + probability;
    }
    
    return ValueOfEvaulation(class_post_prob);
}

int Model::ValueOfEvaulation(double *probabilities) {
    int index = 0;
    double probability = probabilities[0];
    
    for (int i = 1; i < CLASSES; ++i) {
        if (probabilities[i] > probability) {
            probability = probabilities[i];
            index = i;
        }
    }
    
    return index;
}

bool Model::LoadModel(std::string file_location) {
    FileIO file_io;
    
    if (!file_io.OpenFileRead(file_location)) {
        std::cout << "File not open for reading" << std::endl;
        return false;
    }
    
    for (int i = 0; i < CLASSES; ++i) {
        class_count[i] = file_io.ReadInt();
        
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            for (int k = 0; k < IMAGE_SIZE; ++k) {
                double next_feature = file_io.ReadDouble();
                
                if (next_feature == -1) {
                    std::cout << "-1" << std::endl;
                    return false;
                }
                
                model[i][j][k] = next_feature;
            }
        }
    }
    std::cout << "all done" << std::endl;
    file_io.Close();
    return true;
}

std::ostream& operator << (std::ostream& os, const Model& model) {
    for (int i = 0; i < CLASSES; ++i) {
        
        std::string format_model = std::to_string(model.class_count[i]) + " ";
        
        for (int j = 0; j < IMAGE_SIZE; ++j) {
            for (int k = 0; k < IMAGE_SIZE; ++k) {
                format_model += std::to_string(model.model[i][j][k]) + " ";
            }
        }
        
        os << format_model << std::endl;
    }
    
    return os;
}

std::istream& operator >> (std::istream& is, Model& model) {
    std::string file_location;
    bool save_file_loaded = false;
    
    while (!save_file_loaded) {
        std::cout << "Enter saved model location: " << std::endl;
        is >> file_location;
        std::cout << std::endl;
        
        save_file_loaded = model.LoadModel(file_location);
    }
    
    return is;
}
