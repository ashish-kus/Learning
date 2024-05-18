#!/bin/bash
#
#
CONFIG_FILE="~/.config/create_ap/create_ap.conf"

notify() {
  check notify-send && notify-send "$@" || echo "$@"
}

if ! command -v create_ap &>/dev/null; then
    notify "Error: create_ap is not installed. Please install it first."
    exit 1
f

if [ "$EUID" -ne 0 ]; then
    notify "Error: This script must be run as root."
    exit 1
fi

create_access_point() {
    local config_file="$CONFIG_FILE"

    # Check if create_ap process is already running
    if pgrep -x "create_ap" >/dev/null; then
        notify "create_ap process is already running"
    else
        # Check if the configuration file exists
        if [ -f "$config_file" ]; then
            local wifi_interface=$(jq -r '.wifi_interface' "$config_file")
            local internet_interface=$(jq -r '.internet_interface' "$config_file")
            local ssid=$(jq -r '.ssid' "$config_file")
            local password=$(jq -r '.password' "$config_file")
            # Create access point
            create_ap "$wifi_interface" "$internet_interface" "$ssid" "$password"
        else
            notify "Error: Config file not found"
        fi
    fi
}


# Function to check and kill create_ap processes
kill_create_ap() {
    if pgrep -x "create_ap" >/dev/null; then
        pkill create_ap
        notify "create_ap processes killed"
    else
        notify "No create_ap processes Found"
    fi
}

toggle_acesses_point() {
  if pgrep -x "create_ap" >/dev/null; then 
    pkill create_ap
    notify "create_ap processes killed"
  else
    create_acesses_point
  fi
}

setIcon() {
  if pgrep -x "create_ap" >/dev/null; then 
    icon = ""
  else
    icon = ""
  fi
}

waybar_outpur() {
cat << EOF
{ "text":"$icon", "tooltip":"$"}  
EOF
}
# Function to toggle hotspot creation


# Parse command-line options
while getopts ":c:" opt; do
    case ${opt} in
        s )
          create_access_point
            ;;
        \? )
            echo "Invalid option: $OPTARG" 1>&2
            exit 1
            ;;
        : )
            echo "Option -$OPTARG requires an argument." 1>&2
            exit 1
            ;;
    esac
done
shift $((OPTIND -1))

# Check if -c option is provided
if [ -z "$config_file" ]; then
    echo "Usage: $0 -c config_file"
    exit 1
fi
