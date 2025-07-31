# 1. Create the target directory first
mkdir googletest

# 2. Download and extract the tarball into the new directory
wget -O - https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz | tar -xz --strip-components=1 -C googletest