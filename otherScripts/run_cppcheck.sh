# Get the contents from the file named ./configs/configs_for_cppCheck.txt and put it in a variable
CONFIG_FILE="./configs/configs_for_cppCheck.txt"
if [ -f "$CONFIG_FILE" ]; then
    while IFS= read -r line; do
        # Extract variable name and value
        VAR_NAME=$(echo "$line" | awk '{print $1}')
        VAR_VALUE=$(echo "$line" | awk '{print $2}')
        # Export as environment variable
        echo "$VAR_NAME"="$VAR_VALUE"
    done < "$CONFIG_FILE"
else
    echo "Error: Config file $CONFIG_FILE not found."
    exit 1
fi

# COMMAND cppcheck
#         --project="${CMAKE_BINARY_DIR}/compile_commands.json"
#         --enable=all
#         --xml
#         --xml-version=${CPPCHECK_CFG_XML_VERSION}
#         --output-file=${CPPCHECK_REPORTS_XML}
#         --language=c++
#         --std=c++11
#         --platform=${CPPCHECK_CFG_PLATFORM}
#         --encoding=${CPPCHECK_CFG_ENCODING}
#         --template="{file}:{line}:{severity}:{id}:{message}"
#         --force
#         --inline-suppr=${CPPCHECK_CFG_INLINE_SUPPRESSION}
#         --max-ctu-depth=${CPPCHECK_CFG_MAX_CTU_DEPTH}
#         --max-template-recursion=${CPPCHECK_CFG_MAX_TEMPLATE_RECURSION}
#         --check-headers=${CPPCHECK_CFG_CHECK_HEADERS}
#         --check-unused-templates=${CPPCHECK_CFG_CHECK_UNUSED_TEMPLATES}
#         --project=${CPPCHECK_CFG_PROJECT_NAME}
#         --analyze-all-vs-configs=${CPPCHECK_CFG_ANALYZE_ALL_VS_CONFIGS}
#         --suppress-config="${FILE_CPPCHECK_SUPPRESS}"
#         -I "${FILE_CPPCHECK_INCLUDES}"
#         -i "${FILE_CPPCHECK_EXCLUDES}"
#         --file-list="${FILE_CPPCHECK_SOURCES}"