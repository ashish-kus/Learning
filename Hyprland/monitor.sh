#!/bin/bash

# Define monitor names (update as per your setup)
INTERNAL="eDP-1"
EXTERNAL="HDMI-A-2"

# Get user choice
CHOICE=$(echo -e "Duplicate\nExtend\nExternal Only\nLaptop Only" | rofi -dmenu -p "Select Display Mode")

case "$CHOICE" in
"Duplicate")
  hyprctl dispatch moveworkspacetomonitor "1 $EXTERNAL"
  hyprctl keyword monitor "$EXTERNAL,1920x1080@60,0x0,1"
  hyprctl keyword monitor "$INTERNAL,1920x1080@60,0x0,1"
  ;;
"Extend")
  hyprctl keyword monitor "$EXTERNAL,1920x1080@60,1920x0,1"
  ;;
"External Only")
  hyprctl keyword monitor "$INTERNAL,disable"
  hyprctl keyword monitor "$EXTERNAL,1920x1080@60,0x0,1"
  ;;
"Laptop Only")
  hyprctl keyword monitor "$EXTERNAL,disable"
  hyprctl keyword monitor "$INTERNAL,1920x1080@60,0x0,1"
  ;;
*)
  echo "Invalid option or cancelled"
  ;;
esac
