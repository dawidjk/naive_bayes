//
//  ImageSet.hpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/22/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#ifndef ImageSet_hpp
#define ImageSet_hpp

#include <vector>
#include "Image.hpp"

#define MISMATCHED_DIM -1

class ImageSet {
private:
    std::vector<Image> image_set;
    std::vector<int> image_descriptor;
public:
    unsigned long LoadSet(std::string file_location, bool black_white);
    unsigned long LoadDescriptors(std::string file_location);
    unsigned long Size();
    Image GetImageAt(int index);
    int GetDescriptorAt(int index);
};

#endif /* ImageSet_hpp */
