/*
 * Copyright(c) 2018 DBL
 * Author: Nan Zhao
 * Created on: 05/02/2018
 */

#define DBL_EXPORTING // ExportDLL
#include "DBLImage.hpp"
//#include "talk/base/logging.h"

namespace dbl {

DBLImage::DBLImage(size_t width, size_t height, size_t bytes_per_pixel) :
    width_(width), height_(height),
    bytes_per_pixel_(bytes_per_pixel), image_(nullptr) {
    if (width_ > 0 && height_ > 0) {
        size_t size = width_ * height * bytes_per_pixel;
		image_ = new uint8[size];
    }
}

DBLImage::DBLImage(const DBLImage& other) {
	if (this != &other) { // self-check
		size_t size = other.width_ * other.height_ * other.bytes_per_pixel_;
		unsigned char* temp = new unsigned char[size];
		memcpy(temp, other.image_, size);
		width_ = other.width_;
		height_ = other.height_;
		bytes_per_pixel_ = other.bytes_per_pixel_;
		std::swap(image_, temp);
		delete [] temp;
	}
}

DBLImage::~DBLImage() {
  delete[] image_;
}

size_t DBLImage::width() const { return width_;}
size_t DBLImage::height() const { return height_;}
size_t DBLImage::bytesPerPixel() const { return bytes_per_pixel_; }

uint8* DBLImage::image() {
  return image_;
}

}  // namespace dbl
