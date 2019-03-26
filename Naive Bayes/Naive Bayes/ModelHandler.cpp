//
//  ModelHandler.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/26/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "ModelHandler.hpp"
#include <string>
#include "FileIO.hpp"

const int kLaplaceFactor = 1;
const std::string kConfusionMatrix = "Evaulate Confusion Matrix?";
const std::string kLoadModel = "Load model?";
const std::string kTrainModel = "Train Model?";
const std::string kMismatchedDim = "Mismatched dimensions for images and labels";
const std::string kClassificationFile = "Enter classified image save file:";
const std::string kConfusionSuffix = "_Confusion_Matrix";
const std::string kImageSet = "Enter image set location: ";
const std::string kImageDescriptor = "Enter image descriptor location: ";
const std::string kSavedFile = "Enter saved file location: ";
const std::string kSaveFile = "Enter save file location: ";
const std::string kModelSaved = "Model saved";
const std::string kY_N = " (Y/N): ";
const std::string kYes = "Y";
const std::string kNo = "N";
const std::string kSpace = " ";

void ModelHandler::TrainModel() {
    if (!PerformAction(kTrainModel)) {
        return;
    }
    
    LoadImageSet();
    LoadDescriptor();
    if (!model.Train(image_set, kLaplaceFactor)) {
        std::cout << std::endl << kMismatchedDim << std::endl;
    }
    SaveModel();
}

void ModelHandler::ClassifyImages() {
    if (!PerformAction(kLoadModel)) {
        return;
    }
    
    LoadImageSet();
    
    std::cout << kClassificationFile << std::endl;
    std::string file_location;
    std::cin >> file_location;
    
    FileIO file_io;
    file_io.OpenFileWrite(file_location);
    
    std::vector<int> labels;
    
    if (file_io.GetWriteFile().is_open()) {
        for (int i = 0; i < image_set.ImageSetSize() - 1; ++i) {
            labels.push_back(model.Evaluate(image_set.GetImageAt(i)));
            file_io.GetWriteFile() << labels.at(labels.size() - 1) << std::endl;
        }
    }
    
    file_io.Close();
    
    ConfusionMatrix(labels, file_location);
}

void ModelHandler::ConfusionMatrix(std::vector<int> labels, std::string file_location) {
    if (!PerformAction(kConfusionMatrix)) {
        return;
    }
    
    LoadDescriptor();
    
    int confusion_count[CLASSES][CLASSES] = {{ 0 }};
    int counts[CLASSES] = { 0 };
    double confusion_matrix[CLASSES][CLASSES] = {{ 0 }};
    
    for (int i = 0; i < labels.size(); ++i) {
        confusion_count[image_set.GetDescriptorAt(i)][labels.at(i)]++;
    }
    
    for (int i = 0; i < CLASSES; ++i) {
        for (int j = 0; j < CLASSES; ++j) {
            counts[i] += confusion_count[i][j];
        }
    }
    
    FileIO file_io;
    file_io.OpenFileWrite(file_location + kConfusionSuffix);
    
    for (int i = 0; i < CLASSES; ++i) {
        for (int j = 0; j < CLASSES; ++j) {
            confusion_matrix[i][j] = ((double) confusion_count[i][j]) / ((double) counts[i]);
            file_io.GetWriteFile() << std::fixed << confusion_matrix[i][j] << kSpace;
        }
        
        file_io.GetWriteFile() << std::endl << std::endl;
    }
    
    file_io.Close();
}

void ModelHandler::LoadImageSet() {
    int imageset_loaded = FILE_NOT_OPEN;
    
    while (imageset_loaded == FILE_NOT_OPEN) {
        std::string file_location;
        std::cout << kImageSet << std::endl;
        std::cin >> file_location;
        imageset_loaded = (int) image_set.LoadSet(file_location, true);
    }
}

void ModelHandler::LoadDescriptor() {
    int descriptors_loaded = FILE_NOT_OPEN;
    
    while (descriptors_loaded == FILE_NOT_OPEN) {
        std::string file_location;
        std::cout << kImageDescriptor << std::endl;
        std::cin >> file_location;
        descriptors_loaded = (int) image_set.LoadDescriptors(file_location);
    }
}

void ModelHandler::LoadModel() {
    bool model_loaded = false;
    
    while (!model_loaded) {
        std::string file_location;
        std::cout << kSavedFile << std::endl;
        std::cin >> file_location;
        model_loaded = model.LoadModel(file_location);
    }
}

void ModelHandler::SaveModel() {
    FileIO file_io;
    
    std::cout << kSaveFile << std::endl;
    std::string file_location;
    std::cin >> file_location;
    
    file_io.OpenFileWrite(file_location);
    
    if (file_io.GetWriteFile().is_open()) {
        file_io.GetWriteFile() << model;
        std::cout << std::endl << kModelSaved << std::endl;
    }
    
    file_io.Close();
}

bool ModelHandler::PerformAction(std::string action_text) {
    std::string action;
    
    do {
        std::cout << action_text + kY_N;
        std::cin >> action;
    } while (action != kYes && action != kNo);
    
    if (action == kNo) {
        return false;
    }
    
    return true;
}
