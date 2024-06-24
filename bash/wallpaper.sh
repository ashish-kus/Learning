#!/bin/bash

# Directory containing wallpapers
wallpaper_dir="$HOME/Pictures/Wallpaper"

# Transition settings
transition_bezier=".43,1.19,1,.4"
transition_fps=60
transition_type="any" # Replace with desired transition type
transition_duration=0.7

# Check if swww is running, if not start it
if ! pgrep -x "swww-daemon" > /dev/null; then
    swww init
fi

# Select a random wallpaper from the directory
wallpapers=("$wallpaper_dir"/*)
random_wallpaper=$(find "$wallpaper_dir" -type f | shuf -n 1)
# Get current cursor position
cursor_pos="$(hyprctl cursorpos)"

# Set the random wallpaper with transition
swww img "$random_wallpaper" \
    --transition-bezier $transition_bezier \
    --transition-fps=$transition_fps \
    --transition-type=$transition_type \
    --transition-duration=$transition_duration \
    --transition-pos "$cursor_pos"

notify-send "walpaper changed"
