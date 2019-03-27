//
//  Model.hpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/25/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#define CLASSES 10

#include <string>
#include <map>
#include "ImageSet.hpp"

class Model {
private:
    double model[CLASSES][IMAGE_SIZE][IMAGE_SIZE] = {{{ 0 }}};
    int class_count[CLASSES] = { 0 };
    
    int ValueOfEvaulation(double probabilities[CLASSES]);
    friend std::ostream& operator << (std::ostream& os, const Model& model);
    friend std::istream& operator >> (std::istream& is, Model& model);
public:
    bool LoadModel(std::string file_location);
    bool Train(ImageSet set, double smooth_factor);
    int Evaluate(Image image);
};

#endif /* Model_hpp */
