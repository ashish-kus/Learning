#!/bin/bash

parse_ini() {
    local ini_file="$1"
    declare -A config
    local i=0
    current_section=""
    while IFS= read -r line; do
        line=$(echo "$line" | sed -e 's/^[ \t]*//;s/[ \t]*$//')
        # if [[ "$line" =~ ^\; ]] || [[ -z "$line" ]]; then
        #     continue
        # fi

        # if [[ "$line" =~ ^\[.*\]$ ]]; then
        #     current_section=$(echo "$line" | sed -e 's/^\[\(.*\)\]$/\1/')
        # else
        #     key=$(echo "$line" | cut -d '=' -f 1)
        #     value=$(echo "$line" | cut -d '=' -f 2-)
        #     config["$current_section.$key"]=$value
        # fi
        config[i]=$line
        i=i+1
    done < "$ini_file"
    echo $config
    # Export the variables to make them available in the current shell
    # for key in "${!config[@]}"; do
        # export "${key^^}=${config[$key]}"
         # export "${key//./_}=${config[$key]}"
        # export "${key^^}=${config[$key]}"
        # echo $key
    # done
}

# Parse the INI file
ini_file="$1"
parse_ini "$ini_file"
# echo $SECTION1.KEY3
