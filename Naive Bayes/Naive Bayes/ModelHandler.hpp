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
    void ConfusionMatrix(std::vector<int> labels, std::string file_location);
    bool PerformAction(std::string action_text);
public:
    void TrainModel(double smoothing_factor);
    void ClassifyImages();
    double FindBestSmoothingFactor();
};

#endif /* ModelHandler_hpp */
