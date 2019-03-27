//
//  TestModel.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/26/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "Catch2.hpp"
#include "Model.hpp"
#include <string>

TEST_CASE( "Test Load File", "[Model]" ) {
    std::string file = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/training";
    
    Model model;
    
    REQUIRE(model.LoadModel(file));
}

TEST_CASE( "Test Load File Fail", "[Model]" ) {
    std::string file_string = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/training_fake";
    std::remove ("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/training_fake");
    std::string file = file_string;
    
    Model model;
    
    REQUIRE(!model.LoadModel(file));
}


TEST_CASE( "Test Train", "[Model]" ) {
    std::string file_path = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/training";
    
    ImageSet image_set;
    image_set.LoadSet(file_path + "images", true);
    image_set.LoadDescriptors(file_path + "labels");
    
    Model model;
    REQUIRE(model.Train(image_set, 1));
}

TEST_CASE( "Test Train Fail", "[Model]" ) {
    std::string file_path = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/training_fake";
    
    ImageSet image_set;
    image_set.LoadSet(file_path + "images", true);
    image_set.LoadDescriptors(file_path + "labels");
    
    Model model;
    REQUIRE(!model.Train(image_set, 1));
}

TEST_CASE( "Test Evaulate", "[Model]" ) {
    std::string file = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/";
    
    Model model;
    model.LoadModel(file + "training");
    
    ImageSet test_images;
    test_images.LoadSet(file + "testimages", true);
    test_images.LoadDescriptors(file + "testlabels");
    
    REQUIRE(model.Evaluate(test_images.GetImageAt(0)) == 7);
}

TEST_CASE( "Test Evaulate second", "[Model]" ) {
    std::string file = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/";
    
    Model model;
    model.LoadModel(file + "training");
    
    ImageSet test_images;
    test_images.LoadSet(file + "testimages", true);
    test_images.LoadDescriptors(file + "testlabels");
    
    REQUIRE(model.Evaluate(test_images.GetImageAt(1)) == 0);
}
