### Features
- A logger class implemented using the singleton design pattern.
- A single object can be used throught the project for logging.
- 7 level log hierarchy - OFF, CRITICAL, ERROR, WARNING INFO, DEBUG, ALL(default). 

### Usage

- add the `logger.hpp` file in your include folder and specify its path during compilation.
- Either the  `logger.cpp` file can be used in the project or the lib can be downloaded.

#### Limitations
- All logs go into a single file specified during the first request for the logger object.
- Open for any suggestions : )