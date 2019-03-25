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
#include "FileIO.hpp"

class ImageSet {
private:
    std::vector<Image> ImageSet;
public:
    bool LoadSet(std::string file_location);
};

#endif /* ImageSet_hpp */
