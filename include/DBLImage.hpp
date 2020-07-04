/*
* Copyright(c) 2018 DBL
* Author: Nan Zhao
* Created on: 05/02/2018
*/

#ifndef DBLImage_H
#define DBLImage_H

/*
#ifdef  DBL_EXPORTING
#define DBLAPI __declspec(dllexport) 
#else
#define DBLAPI __declspec(dllimport) 
#endif
*/

#include <memory>

namespace dbl {

#define PI 3.141592653589793

typedef unsigned char uint8;

//class DBLAPI DBLImage
class DBLImage
{
public:
	DBLImage(size_t width, size_t height, size_t bytes_per_pixel);
	DBLImage(const DBLImage& other);

	virtual ~DBLImage();

	size_t width() const;
	size_t height() const;
	size_t bytesPerPixel() const;

	uint8* image();

private:
	DBLImage& operator= (const DBLImage& other);
	size_t width_;
	size_t height_;
	size_t bytes_per_pixel_;
	uint8* image_;
};  

}  // namespace dbl
#endif // DBLImage_H
