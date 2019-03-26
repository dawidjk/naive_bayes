//
//  main.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/12/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

// Data Directory:
// /Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/

#include <iostream>
#include <string>

#include "ModelHandler.hpp"

int main(int argc, const char * argv[]) {
    ModelHandler model_handler;
    model_handler.TrainModel();
    model_handler.ClassifyImages();
}
