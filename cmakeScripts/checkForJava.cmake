# 2. Find Java to run the .jar file
find_package(Java REQUIRED)
message(STATUS "Found Java: ${Java_JAVA_EXECUTABLE} (version ${Java_VERSION})")