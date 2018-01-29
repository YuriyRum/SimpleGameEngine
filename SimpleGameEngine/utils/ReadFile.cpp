#include "FileReaderUtil.h"

namespace core
{
	namespace utils
	{
		std::string ReadFile(const char* filePath)
		{
			FILE* file = fopen(filePath, "rt");
			fseek(file, 0, SEEK_END);

			/// set coursor position to the end of the file
			unsigned long length = ftell(file);

			/// create an array for the data
			char* data = new char[length + 1];
			memset(data, 0, length + 1);

			/// set coursor position to the very begining
			fseek(file, 0, SEEK_SET);

			/// read data to the buffer
			fread(data, 1, length, file);

			fclose(file);

			std::string result(data);
			delete[] data;

			return result;
		}
	}
}