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
    int model[CLASSES][IMAGE_SIZE][IMAGE_SIZE];
    int class_count[CLASSES] = {0};
public:
    bool LoadModel(std::string file_location);
    bool SaveModel(std::string file_location);
    bool Train(ImageSet set, int smooth_factor);
};

#endif /* Model_hpp */
