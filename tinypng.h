/*!
 * @file tinypng.h
 * Definition of the TinyPNG C++ wrapper for libPNG.
 * 
 * @author Rahul A. G.
 */

#ifndef __TINY_PNG_H__
#define __TINY_PNG_H__ value

// C++ includes
#include <string>
#include <iostream>
#include <sstream>

// C includes
#include <stdio.h>
#include <stdlib.h>
#include <png.h>

using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

namespace tinypng {

	/*!
	 * Represents a single 32-bit pixel.
	 */
	struct Pixel
	{
		union
		{
			struct {
				uint8_t red, green, blue, alpha;
			};
			uint32_t raw;
		};
	};
	
	/*!
	 * Represents a PNG image.
	 */
	class PNG
	{
	public:

		/*!
		 * Creates a 1px x 1px PNG image.
		 */
		PNG();

		/*!
		 * Creates a PNG image of the desired dimensions.
		 *
		 * @param width Width of the new image.
		 * @param height Height of the new image.
		 */
		PNG(int width, int height);

		/*!
		 * Creates a PNG image from the specified file on disk.
		 *
		 * @param file_name Name of the file to be read in.
		 */
		PNG(string const& file_name);

		/*!
		 * Copy constructor.
		 *
		 * @param other PNG to be copied.
		 */
		PNG(PNG const& other);

		/*!
		 * Destructor
		 */
		~PNG();

		/*!
		 * Assignment operator.
		 *
		 * @param other Image to copy.
		 * @return The current image, for assignment chaining.
		 */
		PNG const& operator=(PNG const& other);

		/*!
		 * Equality operator.
		 *
		 * @param other Image to be checked.
		 * @return Whether the current image is equal to the other image.
		 */
		bool operator==(PNG const& other) const;

		/*!
		 * Inequality operator.
		 *
		 * @param other Image to be checked.
		 * @return Whether the current image is different from the other image.
		 */
		bool operator!=(PNG const& other) const;

		/*!
		 * Pixel access operator. (0,0) is the upper left pixel.
		 *
		 * @param x X-coordinate for the pixel.
		 * @param y Y-coordinate for the pixel.
		 * @return A reference to the pixel at the given coordinates.
		 */
		Pixel* operator()(int x, int y);

		/*!
		 * Const pixel access operator. (0,0) is the upper left pixel.
		 *
		 * @param x X-coordinate for the pixel.
		 * @param y Y-coordinate for the pixel.
		 * @return A reference to the pixel at the given coordinates.
		 */
		Pixel const* operator()(int x, int y) const;

		/*!
		 * Reads in a PNG object from a file. Overwrites any data in the PNG object.
		 * In the event of failure, the object's contents are undefined.
		 *
		 * @param file_name Name of the file to read from.
		 * @return Whether the image was read successfully.
		 */
		bool readFromFile(string const& file_name);

		/*!
		 * Writes a PNG object to a file.
		 *
		 * @param file_name Name of the file to write to.
		 * @return Whether the file was written successfully.
		 */
		bool writeToFile(string const& file_name);

		/*!
		 * Gets the width of the image.
		 *
		 * @return Width of the image.
		 */
		int getWidth() const;

		/*!
		 * Gets the height of the image.
		 *
		 * @return Height of the image.
		 */
		int getHeight() const;

	private:
		int _width;
		int _height;
		Pixel *_pixels;

		static inline bool _pixelsSame(const Pixel& first, const Pixel& second);

		// Helper functions
		void _init();
		void _blank();
		void _copy(PNG const& other);
		void _clampXY(int& width, int& height) const;
		Pixel& _pixelAt(int x, int y) const;
	};

}

#endif