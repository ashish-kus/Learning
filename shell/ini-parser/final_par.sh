#!/bin/bash

parse_ini() {
    local ini_file="$1"

    # Associative array to store key-value pairs
    declare -A config

    # Current section (default section is an empty string)
    current_section=""

    # Read the INI file line by line
    while IFS= read -r line; do
        # Remove leading and trailing whitespaces
        line=$(echo "$line" | sed -e 's/^[ \t]*//;s/[ \t]*$//')

        # Skip comments and empty lines
        if [[ "$line" =~ ^\; ]] || [[ -z "$line" ]]; then
            continue
        fi

        # Check if the line defines a new section
        if [[ "$line" =~ ^\[.*\]$ ]]; then
            current_section=$(echo "$line" | sed -e 's/^\[\(.*\)\]$/\1/')
        else
            # Split the line into key and value
            key=$(echo "$line" | cut -d '=' -f 1)
            value=$(echo "$line" | cut -d '=' -f 2-)

            # Store key-value pair in the associative array
            config["$current_section.$key"]=$value
        fi
    done < "$ini_file"

    # Print the parsed configuration (optional)
    for key in "${!config[@]}"; do
        echo "$key=${config[$key]}"
    done
}

#!/bin/bash

parse_ini() {
    local ini_file="$1"
    declare -A config

    current_section=""
    while IFS= read -r line; do
        line=$(echo "$line" | sed -e 's/^[ \t]*//;s/[ \t]*$//')
        if [[ "$line" =~ ^\; ]] || [[ -z "$line" ]]; then
            continue
        fi

        if [[ "$line" =~ ^\[.*\]$ ]]; then
            current_section=$(echo "$line" | sed -e 's/^\[\(.*\)\]$/\1/')
        else
            key=$(echo "$line" | cut -d '=' -f 1)
            value=$(echo "$line" | cut -d '=' -f 2-)
            config["$current_section.$key"]=$value
        fi
    done < "$ini_file"

    for key in "${!config[@]}"; do
        echo "$key=${config[$key]}"
    done
}

# Parse the INI file
ini_file="example.ini"
parse_ini "$ini_file"

# Set variables based on the parsed configuration
Section1_key1="${config[Section1.key1]}"
Section1_key2="${config[Section1.key2]}"
Section2_key3="${config[Section2.key3]}"
Section2_key4="${config[Section2.key4]}"

# Example usage of the variables
echo "Section1_key1: $Section1_key1"
echo "Section1_key2: $Section1_key2"
echo "Section2_key3: $Section2_key3"
echo "Section2_key4: $Section2_key4"

# Example usage
ini_file="$1"
parse_ini "$ini_file"
