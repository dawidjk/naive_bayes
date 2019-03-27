//
//  ImageTesting.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/26/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#include "Catch2.hpp"
#include "Image.hpp"
#include "FileIO.hpp"
#include <string>

TEST_CASE( "Open Read File Successfully", "[FileIO]" ) {
    FileIO file_io;
    file_io.OpenFileRead("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/trainingimages");
    
    std::string image_arr[28];
    
    for (int i = 0; i < IMAGE_SIZE; ++i) {
        image_arr[i] = file_io.ReadInt();
    }
    
    Image image;
    image.LoadImage(image_arr, true);
    
    REQUIRE((char) image.GetValue(8, 11) == '#');
}
