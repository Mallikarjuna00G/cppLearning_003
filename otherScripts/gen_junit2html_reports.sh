#!/bin/bash

# Define the source directory where the XML files are located.
# You can change this path as needed.
XML_SOURCE_DIR="./Testing/Reports"

# Define the destination directory for the generated HTML reports.
XML_HTML_REPORTS_DIR="$XML_SOURCE_DIR/xml_html_reports"

# Check if the junit2html command exists.
if ! command -v junit2html &> /dev/null
then
    echo "Error: 'junit2html' is not installed. Please install it with 'pip install junit2html'."
    exit 1
fi

# Create the output directory if it doesn't exist.
mkdir -p "$XML_HTML_REPORTS_DIR"

xml_files="$XML_SOURCE_DIR"/*.xml
rm "$XML_SOURCE_DIR"/combined_xml_report.xml

junit2html $xml_files --merge "$XML_SOURCE_DIR"/combined_xml_report.xml
xml_files="$XML_SOURCE_DIR"/*.xml
echo $xml_files
# Loop through all files ending with .xml in the source directory.
for xml_file in ${xml_files[@]}
do
    # Check if a file was actually found by the glob pattern.
    if [ -f "$xml_file" ]; then
        # Get the filename (e.g., TestReport.xml) without the path.
        filename=$(basename "$xml_file")

        # Define the output path for the HTML file.
        # It will be named like TestReport.xml.html
        output_html="$XML_HTML_REPORTS_DIR/$filename.html"

        echo "Converting $filename to HTML..."

        # Execute junit2html to create the report.
        junit2html "$xml_file" "$output_html"

        echo "Generated report: $output_html"
    fi
done

echo "All XML reports have been converted and stored in the '$XML_HTML_REPORTS_DIR' folder."