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

void ModelHandler::TrainModel() {
    std::string train_model;
    
    do {
        std::cout << "Train Model? (Y/N): ";
        std::cin >> train_model;
    } while (train_model != "Y" && train_model != "N");
    
    if (train_model == "N") {
        return;
    }
    
    LoadImageSet();
    LoadDescriptor();
    if (!model.Train(image_set, 1)) {
        std::cout << std::endl << "Mismatched dimensions for images and labels" << std::endl;
    }
    SaveModel();
}

void ModelHandler::ClassifyImages() {
    std::string load_model;
    
    do {
        std::cout << "Load model (Y/N)";
        std::cin >> load_model;
    } while (load_model != "Y" && load_model != "N");
    
    if (load_model == "Y") {
        LoadModel();
    }
    
    LoadImageSet();
    
    std::cout << "Enter classified image save file:" << std::endl;
    std::string file_location;
    std::cin >> file_location;
    
    FileIO file_io;
    file_io.OpenFileWrite(file_location);
    
    if (file_io.GetWriteFile().is_open()) {
        for (int i = 0; i < image_set.Size(); ++i) {
            file_io.GetWriteFile() << model.Evaluate(image_set.GetImageAt(i)) << std::endl;
        }
    }
    
    file_io.Close();
}

void ModelHandler::LoadImageSet() {
    int imageset_loaded = FILE_NOT_OPEN;
    while (imageset_loaded == FILE_NOT_OPEN) {
        std::string file_location;
        std::cout << "Enter image set location: " << std::endl;
        std::cin >> file_location;
        imageset_loaded = (int) image_set.LoadSet(file_location, true);
    }
}

void ModelHandler::LoadDescriptor() {
    int descriptors_loaded = FILE_NOT_OPEN;
    while (descriptors_loaded == FILE_NOT_OPEN) {
        std::string file_location;
        std::cout << "Enter image descriptor location: " << std::endl;
        std::cin >> file_location;
        descriptors_loaded = (int) image_set.LoadDescriptors(file_location);
    }
}

void ModelHandler::LoadModel() {
    bool model_loaded = false;
    while (!model_loaded) {
        std::string file_location;
        std::cout << "Enter saved file location: " << std::endl;
        std::cin >> file_location;
        model_loaded = model.LoadModel(file_location);
    }
}

void ModelHandler::SaveModel() {
    FileIO file_io;
    
    std::cout << "Enter save file location: " << std::endl;
    std::string file_location;
    std::cin >> file_location;
    
    file_io.OpenFileWrite(file_location);
    
    if (file_io.GetWriteFile().is_open()) {
        file_io.GetWriteFile() << model;
        std::cout << std::endl << "Model saved" << std::endl;
    }
    
    file_io.Close();
}
