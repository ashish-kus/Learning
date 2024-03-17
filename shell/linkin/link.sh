#!/bin/bash

DOTFILES_PATH="$1"
# COMMON_DIR="$HOME/dotfiles"  # Change this to your preferred common directory

create_symlinks() {
  directory_list=$(find "$DOTFILES_PATH" -mindepth 1 -type f -not -name 'install.sh')

  for entry in $directory_list; do
    modified_entry="${entry#./}"
    modified_entry="${modified_entry#*/}"

    absolute_path=$(realpath "${entry#./}")
    absolute_modified_entry="$COMMON_DIR/$modified_entry"

    target_dir="$(dirname "$absolute_modified_entry")"

    # Create the target directory if it doesn't exist
    mkdir -p "$target_dir"

    echo "$absolute_path >>>> $absolute_modified_entry"
    # ln -sf "$absolute_path" "$absolute_modified_entry"
    echo " -"
    # Add your additional logic or commands here
  done
}

create_symlinks "$DOTFILES_PATH"
