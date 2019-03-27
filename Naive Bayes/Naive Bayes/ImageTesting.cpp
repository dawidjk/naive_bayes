//
//  ImageTesting.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/26/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "Catch2.hpp"
#include "Image.hpp"
#include "ImageSet.hpp"
#include "FileIO.hpp"
#include <string>

TEST_CASE( "Read Image Successfully", "[Image]" ) {
    FileIO file_io;
    file_io.OpenFileRead("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/trainingimages");
    
    std::string image_arr[28];
    
    for (int i = 0; i < IMAGE_SIZE; ++i) {
        image_arr[i] = file_io.ReadLine();
    }
    
    Image image;
    image.LoadImage(image_arr, true);
    
    REQUIRE((char) image.GetValue(8, 11) == '#');
}

TEST_CASE( "Load Set Successfully", "[Image]" ) {
    FileIO file_io;
    std::string file = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/trainingimages";
    file_io.OpenFileRead(file);
    
    std::string image_arr[28];
    
    for (int i = 0; i < IMAGE_SIZE; ++i) {
        image_arr[i] = file_io.ReadLine();
    }
    
    Image image;
    image.LoadImage(image_arr, true);
    
    ImageSet image_set;
    image_set.LoadSet(file, true);
    
    REQUIRE(image.GetValue(8, 11) == image_set.GetImageAt(0).GetValue(8, 11));
}

TEST_CASE( "Load Descriptor Successfully", "[Image]" ) {
    FileIO file_io;
    std::string file = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/traininglabels";
    file_io.OpenFileRead(file);
    
    int descriptor = file_io.ReadInt();
    
    ImageSet image_set;
    image_set.LoadDescriptors(file);
    
    REQUIRE(descriptor == image_set.GetDescriptorAt(0));
}

TEST_CASE( "Check Size Correctly", "[Image]" ) {
    FileIO file_io;
    std::string file_path = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/training";
    
    ImageSet image_set;
    image_set.LoadSet(file_path + "images", true);
    image_set.LoadDescriptors(file_path + "labels");
    
    REQUIRE(image_set.Size() == 5000);
}
