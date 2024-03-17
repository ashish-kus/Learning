#!/bin/bash

parse_ini() {
    local ini_file="$1"
    local current_section=""
    
    while IFS= read -r line; do
        # Remove leading and trailing whitespaces
        line=$(echo "$line" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')

        # Skip comments and empty lines
        if [[ "$line" =~ ^[[:space:]]*# || -z "$line" ]]; then
            continue
        fi

        # Check for section
        if [[ "$line" =~ ^\[[^\]]+\]$ ]]; then
            current_section=$(echo "$line" | sed -e 's/^\[\(.*\)\]$/\1/')
        else
            # Extract key and value
            key=$(echo "$line" | cut -d'=' -f1)
            value=$(echo "$line" | cut -d'=' -f2-)

            # Remove leading and trailing whitespaces from key and value
            key=$(echo "$key" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')
            value=$(echo "$value" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')

            # Print the section, key, and value
            echo "Section: $current_section, Key: $key, Value: $value"
        fi
    done < "$ini_file"
}

# Example usage
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <ini_file>"
    exit 1
fi

ini_file="$1"
parse_ini "$ini_file"
