# getGoogleTest.py

import os
import tarfile
import io
import sys
import urllib.request
import urllib.error

def get_googletest(version="release-1.12.1"):
    """
    Downloads and extracts a specified version of the Googletest library
    into a 'googletest' directory using only built-in Python libraries.

    Args:
        version (str): The Git tag for the desired version of googletest.
    """
    # The URL for the tarball
    url = f"https://github.com/google/googletest/archive/refs/tags/{version}.tar.gz"
    
    # 1. Create the target directory
    target_dir = "googletest"
    if not os.path.exists(target_dir):
        os.makedirs(target_dir)
        print(f"Created directory: {target_dir}")
    else:
        print(f"Directory '{target_dir}' already exists. Skipping creation.")

    print(f"Downloading Googletest version '{version}'...")
    try:
        # 2. Download the tarball from the URL using urllib
        with urllib.request.urlopen(url) as response:
            # Read the content and use a BytesIO object for in-memory handling
            tar_stream = io.BytesIO(response.read())

        # Open the tarball for reading
        with tarfile.open(fileobj=tar_stream, mode="r:gz") as tar:
            # We get the top-level directory name (e.g., 'googletest-release-1.12.1')
            top_level_dir = os.path.commonprefix(tar.getnames())
            
            # The --strip-components=1 functionality
            print("Extracting files...")
            for member in tar.getmembers():
                if member.name.startswith(top_level_dir):
                    # Strip the top-level directory from the path
                    member.name = os.path.relpath(member.name, top_level_dir)
                    
                    # Skip the root directory itself to avoid errors
                    if member.name == ".":
                        continue
                    
                    # Extract the member into the target directory
                    tar.extract(member, path=target_dir)
        
        print("Googletest successfully downloaded and extracted.")

    except urllib.error.URLError as e:
        print(f"Error downloading the file: {e.reason}", file=sys.stderr)
        sys.exit(1)
    except tarfile.TarError as e:
        print(f"Error extracting the tarball: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    get_googletest()