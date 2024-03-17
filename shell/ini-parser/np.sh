#!/usr/bin/env bash

CONFIG=$1


parse_ini() {
    local ini_file="$1"
    declare -A ini_array  # Declare an associative array to store variables

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

            # Store the key and value in the associative array
            ini_array["$current_section.$key"]=$value
        fi
    done < "$ini_file"

    # Return the associative array
    echo "${!ini_array[@]}"  # Print the keys for demonstration purposes
}

# Example usage in another script
# parsed_ini=$(parse_ini "your_ini_file.ini")

# Now you can access the variables from the parsed_ini variable
# declare -A ini_array
# eval "$parsed_ini"  # This will define the associative array ini_array

# Accessing values
# section="Section1"
# key="Key1"
# echo "Value of '$section.$key': ${ini_array["$section.$key"]}"
array=$(parse_ini $CONFIG)


for s in ${!array[@]}; do
  for k in ${!array["$s"]}; do
    echo "${s}.${k}=${array["$s.$k"]}"
  done  
done

# for s in array; do
#   for k in s; do
#     echo array[$s.$k]
#   done  
# done
# rows=${#array[@]}
# columns=${#array[0]}
# echo $rows $columns

# # # Print all elements in the 2D array
# for ((i = 0; i < rows; i++)); do
#   for ((j = 0; j < columns; j++)); do
#      echo -n "${array[i][j]} "
#   done
#   echo
# done



