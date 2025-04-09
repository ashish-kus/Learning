#!/bin/bash

# Define the path to the .todo file
TODO_FILE="$HOME/.todo"

# Ensure the .todo file exists
if [[ ! -f "$TODO_FILE" ]]; then
  echo "Error: '$TODO_FILE' does not exist. Creating it..."
  touch "$TODO_FILE" || {
    echo "Failed to create '$TODO_FILE'. Check permissions."
    exit 1
  }
fi

# Ensure the .todo file is readable
if [[ ! -r "$TODO_FILE" ]]; then
  echo "Error: '$TODO_FILE' is not readable. Check permissions."
  exit 1
fi

# Display tasks in rofi and capture the selected task
SELECTED_TASK=$(cat "$TODO_FILE" | rofi -dmenu -p "To-Do")

# Exit if no task is selected
if [[ -z "$SELECTED_TASK" ]]; then
  exit 0
fi

# Debugging: Output the selected task
echo "Selected Task: '$SELECTED_TASK'"

# Process the selected task
if [[ "$SELECTED_TASK" == "󰱒  "* ]]; then
  # If the task is marked as not done (󰱒), toggle to done ()
  NEW_TASK=$(echo "$SELECTED_TASK" | sed 's/^󰱒  /  /')
elif [[ "$SELECTED_TASK" == "  "* ]]; then
  # If the task is marked as done (), toggle to not done (󰱒)
  NEW_TASK=$(echo "$SELECTED_TASK" | sed 's/^  /󰱒  /')
else
  echo "Error: Invalid task format."
  exit 1
fi

# Debugging: Output the new task
echo "New Task: '$NEW_TASK'"

# Update the .todo file with the toggled task
# Escape special characters for sed to handle them correctly
ESCAPED_SELECTED_TASK=$(printf '%s\n' "$SELECTED_TASK" | sed -e 's/[&/\]/\\&/g')
ESCAPED_NEW_TASK=$(printf '%s\n' "$NEW_TASK" | sed -e 's/[&/\]/\\&/g')

sed -i "s|$ESCAPED_SELECTED_TASK|$ESCAPED_NEW_TASK|" "$TODO_FILE"

# Confirmation
echo "Task toggled successfully!"
