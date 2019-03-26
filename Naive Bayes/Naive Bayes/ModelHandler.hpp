//
//  ModelHandler.hpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/26/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#ifndef ModelHandler_hpp
#define ModelHandler_hpp

#include "Model.hpp"
#include <iostream>

class ModelHandler {
private:
    ImageSet image_set;
    Model model;
    void LoadModel();
    void LoadImageSet();
    void LoadDescriptor();
    void SaveOutput();
    void SaveModel();
public:
    void TrainModel();
    void ClassifyImages();
};

#endif /* ModelHandler_hpp */
